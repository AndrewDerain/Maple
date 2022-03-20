
import os
from src.scripts.utility import command


os.system("git submodule update --init")


os.system(command("Catch2", "config"))
os.system(command("Catch2", "build"))
os.system(command("Catch2", "install"))
