import sys
import os
from pathlib import Path
import subprocess
import Utils

class VcpkgConfiguration:
    #vcpkgpath可以手动设置，把你装的vcpkg所在目录写进去
    vcpkgpath=""
    vcpkgurl ="https://github.com/microsoft/vcpkg"
    def __init__(self):
        pass

    @classmethod
    def Validate(cls):
        if (not cls.CheckIfVcpkgInstalled()):
            print("Vcpkg 未安装。")
            return False

        print(f" Vcpkg 位于 {os.path.abspath(cls.vcpkgpath)}")
        return True

    @classmethod
    def CheckIfVcpkgInstalled(cls):
        vcpkgexe = Path(f"{cls.vcpkgpath}/vcpkg.exe");
        if (not vcpkgexe.exists()):
            return False
        else:
            return True

    @classmethod
    def InstallVcpkg(cls):
        installed = False
        while not installed:
            reply = str(input("需要Vcpkg管理器，你本地已经安装过Vcpkg了吗? [Y/N]: ")).lower().strip()[:1]
            
            if reply == 'y':
                replypath=str(input("请告诉我vcpkg.exe的路径 (比如C:\\Program Files\\vcpkg): "))
                if not os.path.exists(replypath+"\\vcpkg.exe") :
                    continue
                else:
                    cls.vcpkgpath=replypath
            elif reply == 'n':
                replyinstall = str(input("现在将为你安装Vcpkg,如果默认安装我会把它安装到C:\\Program Files\\vcpkg(不建议),如果回答N，由你来指定安装位置，我建议你手动指定，那么现在你要默认安装吗? [Y/N]: ")).lower().strip()[:1]
                if replyinstall=='y':
                    replypath="C:\\Program Files"
                elif replyinstall=='n':
                    replypath=str(input("请告诉我要按照的路径 (注意文件夹必须为空,比如D:\\Program Files\\vcpkg): "))
                else:
                    continue
                if replypath!="":
                    print(cls.vcpkgurl)
                    print(replypath)
                    subprocess.call(["git", "clone", cls.vcpkgurl, replypath])
                    if not os.path.exists(replypath +"\\bootstrap-vcpkg.bat"):
                        print("未找到bootstrap-vcpkg.bat")
                        continue
                    else:
                        if not os.path.exists(replypath +"\\vcpkg.exe"):
                            print("未找到vcpkg.exe,准备下载安装...")
                            subprocess.call([replypath+"\\bootstrap-vcpkg.bat"])
                        else:
                            cls.vcpkgpath=replypath
                            print("安装vcpkg.exe成功,安装路径在"+replypath +",请注意留意这个位置，为了方便使用，建议你添加环境变量。")
                else:
                    continue        
            else:
                continue		
            installed = os.path.exists(replypath+"\\vcpkg.exe")

        if installed:
            return True
        else:
            return False
    @classmethod
    def InstallPackage(cls,packagename,platform):
        if platform!= "x64-windows":
            return False
        if not cls.Validate():
            return False
        else:
            subprocess.call([cls.vcpkgpath+"\\vcpkg.exe","install",packagename+":"+platform])
        if not Path(f"{cls.vcpkgpath}/packages/"+packagename+"_"+platform).exists():
            return False
        else:
            return True  