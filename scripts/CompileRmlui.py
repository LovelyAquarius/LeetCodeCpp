import sys
import os
from pathlib import Path
import subprocess
import Utils

class RmluiConfiguration:
    rmluiurl="https://github.com/mikke89/RmlUi.git"
    rmlpath="./vendor/Rmlui"
    def __init__(self):
        pass
    
	#先不用
    @classmethod
    def GetRmlui(cls):
        downloaded = False
        while not downloaded:
            replypath = str(input("现在要下载并编译Rmlui,请告诉我你要下载的路径(注意这个路径可以任意指定，但文件夹必须为空，待编译完成后可以自行删除): "))
            if replypath!="":
                subprocess.call(["git", "clone", cls.rmluiurl, replypath])
            if not os.path.exists(replypath +"\\CMakeLists.txt"):
                        print("未找到CMakeLists.txt")
                        continue
            cls.rmlpath=replypath
            downloaded =True
            
    @classmethod
    def CheckCmake(cls):
        try:
            output = subprocess.check_output(['cmake', '--version'], stderr=subprocess.STDOUT)
            return True
		
        except subprocess.CalledProcessError:
            return False
        
    @classmethod
    def CheckSource(cls):
         if not os.path.exists(cls.rmlpath +"\\CMakeLists.txt"):
            print("未找到CMakeLists.txt")
            return False
         else:
              return True        
             
    @classmethod
    def CompileRmlui(cls,vcpkgpath):
          if not cls.CheckCmake():
               print("请先自行安装cmake！再来启动这个脚本！")
               return False
          else:
               subprocess.call(["cmake", "-B","./vendor/Rmlui/build", "-S",cls.rmlpath,f'-DBUILD_SAMPLES=ON -DCMAKE_TOOLCHAIN_FILE="{vcpkgpath}/scripts/buildsystems/vcpkg.cmake"'])
               subprocess.call(["cmake", "--build","./vendor/Rmlui/build"])