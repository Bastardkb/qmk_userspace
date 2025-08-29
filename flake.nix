{
  description = "my keeb";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixpkgs-unstable";
    flake-parts.url = "github:hercules-ci/flake-parts";
    flake-root.url = "github:srid/flake-root";
    treefmt-nix.url = "github:numtide/treefmt-nix";
    treefmt-nix.inputs.nixpkgs.follows = "nixpkgs";
  };

  outputs = inputs:
    inputs.flake-parts.lib.mkFlake { inherit inputs; } {
      systems = [
        "aarch64-darwin"
        "aarch64-linux"
        "x86_64-darwin"
        "x86_64-linux"
      ];
      imports = [
        # inputs.haskell-flake.flakeModule
        inputs.treefmt-nix.flakeModule
        inputs.flake-root.flakeModule
      ];
      perSystem =
        { pkgs
        , lib
        , config
        , system
        , ...
        }:

        {
          packages.drawer = pkgs.python3Packages.callPackage ./nix/keymap-drawer.nix { };

          treefmt.config = {
            inherit (config.flake-root) projectRootFile;
            package = pkgs.treefmt;

            programs.nixpkgs-fmt.enable = true;

          };

          packages.draw = pkgs.writeShellApplication {
            name = "reiryoku-draw";
            runtimeInputs = with pkgs;
              [
                config.packages.drawer
                (python3.withPackages (ps: [ ps.pyyaml ]))
              ];
            text = ''
              keymap parse -c 10 -q ${config.packages.firmware}/share/reiryoku.json  > reiryoku.yaml
               sed -i -E "s/LAYOUT_charybdis_3x5/LAYOUT/g" reiryoku.yaml
              keymap draw reiryoku.yaml > reiryoku.svg
               python process.py
               keymap draw output.yaml > reiryoku.svg
            '';
          };

          # Default shell.
          devShells.default = pkgs.mkShell {
            buildInputs = with pkgs; [
              (python3.withPackages (ps: [ ps.pyyaml ]))
              config.packages.drawer
              qmk
              stow
            ];
            #https://github.com/EdenEast/qmk/blob/main/flake.nix
            shellHook = ''
              # Prevent the avr-gcc wrapper from picking up host GCC flags
              # like -iframework, which is problematic on Darwin
              unset NIX_CFLAGS_COMPILE_FOR_TARGET
            '';

            # See https://haskell.flake.page/devshell#composing-devshells
            inputsFrom = [
              config.flake-root.devShell
              config.treefmt.build.devShell
            ];
          };
        };
    };
}
