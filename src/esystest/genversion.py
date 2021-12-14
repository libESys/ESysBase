#!/usr/bin/env python3

import os

from tomlkit import exceptions, parse, table
import string


class GenVersion:
    def __init__(self) -> None:
        self.m_toml_file = None
        self.m_template_file = None
        self.m_output_file = None

    def set_cz_toml(self, toml_file) -> None:
        self.m_toml_file = toml_file

    def set_template_file(self, template_file) -> None:
        self.m_template_file = template_file

    def set_output_file(self, output_file) -> None:
        self.m_output_file = output_file

    def generate(self) -> None:
        with open(self.m_toml_file, "rb") as f:
            parser = parse(f.read())
        version = parser["tool"]["commitizen"]["version"]
        versions = version.split(".")

        with open(self.m_template_file) as t:
            template = string.Template(t.read())

        final_output = template.safe_substitute(
            major=versions[0], minor=versions[1], patch=versions[2]
        )
        with open(self.m_output_file, "w") as output:
            output.write(final_output)


if __name__ == "__main__":
    root_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../.."))
    gen_version = GenVersion()
    gen_version.set_cz_toml(os.path.abspath(os.path.join(root_path, ".cz.toml")))
    gen_version.set_template_file(
        os.path.abspath(
            os.path.join(root_path, "src", "esystest", "version_defs.temph")
        )
    )
    gen_version.set_output_file(
        os.path.abspath(
            os.path.join(root_path, "include", "esystest", "version_defs.h")
        )
    )

    gen_version.generate()
