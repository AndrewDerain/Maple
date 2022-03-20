

import os

def command(submodule, cmd_type):
    cmd = ""
    install_prefix = "--install-prefix " + os.path.abspath("./thirdparty/")
    source_dir = os.path.abspath("./thirdparty/src/") + "/" + submodule
    binary_dir = os.path.abspath("./out/build_thirdparty/") + "/" + submodule

    if cmd_type == "config":
        cmd += " cmake " + install_prefix
        cmd += " -S " + source_dir
        cmd += " -B " + binary_dir

    if cmd_type == "build":
        cmd += "cmake --build " + binary_dir

    if cmd_type == "install":
        cmd += "cmake --install " + binary_dir

    return cmd
