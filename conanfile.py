from conans import ConanFile, CMake, tools


class ESysTestConan(ConanFile):
    name = "ESysTest"
    version = "0.1.0"
    license = "wxWindows Library Licence, Version 3.1"
    author = "Michel Gillet michel.gillet@libesys.org"
    url = "https://gitlab.com/libesys/esystest"
    description = "C++ Unit Test Framework for both CPU and MCU"
    topics = ("c++", "testing", "UT", "unit testing")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    generators = "cmake", "cmake_find_package", "virtualrunenv"
    requires = "boost/1.71.0"
    default_options = {"shared": True, "fPIC": True, "boost:shared": True}
    exports_sources = [
        "include/*",
        "project/*",
        "src/*",
        "res/*",
        "samples/*",
        "scripts/*",
        "test_packege/*",
        "CMakeLists.txt",
    ]

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def build(self):
        cmake = CMake(self)
        cmake.definitions["ESYSTEST_BUILD_VHW"] = 1
        cmake.definitions["ESYSTEST_MULTIOS"] = 1
        # cmake.definitions["ESYSTEST_USE_ESYSTEST 1)
        cmake.definitions["ESYSTEST_USE_BOOST"] = 1
        cmake.definitions["ESYSTEST_USE_CONAN"] = "On"
        cmake.configure()
        cmake.build()
        cmake.install()

    def package(self):
        self.copy("*.h", dst="include/esystest", src="include/esystest")
        self.copy("*esystest.lib", dst="lib", keep_path=False)
        # self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*libesystest.so*", dst="lib", keep_path=False)
        # self.copy("project/cmake/*.cmake", dst="lib/cmake", keep_path=False)
        self.copy("esystest*.cmake", dst="lib/cmake", keep_path=False)
        # self.copy("*.dylib", dst="lib", keep_path=False)
        # self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["esystest"]
