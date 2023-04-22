import sys
import os
from pathlib import Path
import subprocess
import Utils
import git
import urllib.request
import zipfile
import shutil

class RmluiConfiguration:
    freetypelibpath=f"vendor/Rmlui/Dependencies/lib"
    freetypeincludepath =f"vendor/Rmlui/Dependencies/include"
    srcpath=f"vendor/freetype-windows-binaries"
    Rmluilibpath =f"vendor/Rmlui/build/Debug"
    

    @classmethod
    def checkRmlui(cls):
        return Path(cls.Rmluilibpath+"/RmlCore").exists()


    @classmethod
    def checkfreetype(cls):
        return Path(cls.srcpath).exists()

    @classmethod
    def importfreetypelib(cls):
        if not cls.checkfreetype():
            print("子模块安装失败，请检查网络后重新运行这个脚本")
            return False
        if not Path(cls.freetypelibpath+"freetype.lib").exists():
            cls.copyfile(cls.srcpath+f"/release static/vs2015-2022/win64/freetype.lib",cls.freetypelibpath,"freetype.lib")
        return True
        
    @classmethod
    def importfreetypeinclude(cls):
        if not cls.checkfreetype():
            print("子模块安装失败，请检查网络后重新运行这个脚本")
            return False
        if not Path(cls.freetypeincludepath+"/ft2build.h").exists():
            if not Path(cls.freetypeincludepath).exists():
                os.mkdir(cls.freetypeincludepath)
            cls.copydir(cls.srcpath+f"/include", cls.freetypeincludepath)
        return True
        
    @classmethod
    def copyfile(cls,src,dst,filename):#dst是文件夹
        if not os.path.exists(dst):
            os.mkdir(dst)
        fdst = os.path.join(dst,filename)  
        shutil.copyfile(src,fdst)

    @classmethod
    def copydir(cls,src,dst):
        files=os.listdir(src)
        for i in files:
            i_src = os.path.join(src,i)
            i_dst= os.path.join(dst,i)
            if os.path.isdir(i_src):
                if not os.path.exists(i_dst):
                    os.mkdir(i_dst)
                cls.copydir(i_src,i_dst)
            else:
                if not os.path.exists(i_dst):
                    shutil.copyfile(i_src,i_dst)