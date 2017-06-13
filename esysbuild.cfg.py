from esysbuild.lib import *
from esysbuild.exe import *
from esysbuild.buildfile import *

class ESysTestBuildFile(BuildFile):
    def __init__(self):
        super().__init__()
        self.SetBootStrapScript("config/bootstrap")
        
    def AddLibs(self, lib_mngr):   
        vhw_hw=["vhw", "hw"]
        
        esystest=Lib("esystest")
        esystest.AddGroupName(vhw_hw)
        esystest.SetLinkCfg(Lib.LINK_LIBTOOL, "src/esystest/libesystest.la")
        esystest.SetLinkCfg(Lib.LINK_INSTALLED, "-lesystest")
        #esystest.AddDependencies(["esys"])
        lib_mngr.Add(esystest)
        
        esystest_t=Exe("esystest_t")
        esystest_t.AddGroupName("vhw")
        #esystest_t.AddDependencies(["esys", "esystest"])
        esystest_t.AddDependencies(["esystest"])
        lib_mngr.Add(esystest_t)            
        return 0
    
def GetBuildFile():
    return ESysTestBuildFile()



    