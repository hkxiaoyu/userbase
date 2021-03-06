#pragma once
#include <string>
#include <vector>
#include <Shlwapi.h>
#include <shlobj.h>
#include <io.h>

namespace ubase
{
	//文件的IO
	bool FsReadFile(const std::string &filePath, std::string &data);//读取文件
	bool FsWriteFile(const std::string &filePath, std::string &data);//写入文件

	//文件校验
	std::string FsGetFileMD5(std::string &filePath);//获取文件的MD5值

	//系统特殊路径的获取(路径带反斜杠)
	std::string FsGetDesktopPath();//获取文件夹的绝对路径
	std::string FsGetDocumentPath();//获取文档文件夹的绝对路径
	std::string FsGetProgramPath();//获取应用程序安装路径
	std::string FsGetTempPath();//获取临时文件夹
	std::string FsGetWindowsPath();//获取windows文件夹
	std::string FsGetSystem32Path();//获取Symtem32文件夹
	std::string FsGetCSIDLPath(IN int nCSIDL);//获取特殊路径--SHGetSpecialFolderPath实现

	//与文件路径有关的操作
	std::string FsGetProcessFullPath();//获取进程的PE文件全路径
	std::string FsGetProcessPath();//获取进程的路径带反斜杠
	std::string FsGetFileName(IN const std::string& strFilePath);//根据文件的全路径获取文件的名称
	std::string FsGetFileExt(IN const std::string& strFilePath);//获取文件的扩展名
	std::string FsGetFilePath(IN const std::string& strFilePath);//通过文件全路径获取文件的路径,获取的路径带反斜杠
	void FsAddBackslash(IN OUT std::string& strDir);//路径上面加上反斜杠
	void FsDelBackslash(IN OUT std::string& strDir);//去掉路径后面的反斜杠
	bool FsIsDir(IN const std::string& strPath);//判断路径是否是文件夹
	bool FsIsFile(IN const std::string& strFilePath);//判断路径是否是文件
	bool FsIsFileExists(const std::string& path);//判断文件是否存在

	//与文件属性相关
	__int64 FsGetFileSize(IN const std::string& strFileName);//获取文件的大小,单位是longlong或者__int64类型,能够表示大于4G的文件大小
	LONGLONG FsGetModiftyTime(IN const std::string& strFile);//获取文件修改的时间(时间是UNIX时间戳)
	LONGLONG FsGetCreateTime(IN const std::string& strFile);//获取文件创建的时间(时间是UNIX时间戳)
	LONGLONG FsGetAccessTime(IN const std::string& strFile);//获取文件最后访问的时间(时间是UNIX时间戳)
	

	//文件操作
	bool FsDeleteFileEx(IN const std::string& strFileName);//删除文件(如果删除不掉会尝试设置文件属性,然后再次删除)
	bool FsMoveFileEx(IN const std::string& strSrc, IN OUT std::string& strDst);//移动文件
	bool FsForceCreateDir(IN const std::string& strDir);//循环创建文件夹
	void FsForceDeleteDir(IN const std::string& strDir);//循环删除文件夹

	//文件自删除
	BOOL FsRebootDelete(char *pszFileName);//重启自删除文件
	BOOL FsDelSelf(int iType);//通过构造批处理文件的方式自删除

	//遍历文件
	void FsErgodicFiles(char *pszDirectory, std::vector<std::string> &fileVector);//遍历文件获取指定文件夹下所有文件的路径

	//文件压缩
	bool CompressData(BYTE *pUncompressData, DWORD dwUncompressDataLength, BYTE **ppCompressData, DWORD *pdwCompressDataLength);//压缩数据,返回指针,需要自行释放内存
	bool UncompressData(BYTE *pCompressData, DWORD dwCompressDataLength, BYTE **ppUncompressData, DWORD *pdwUncompressDataLength);//解压缩数据,返回指针,需要自行释放内存

	//PE文件相关常用操作
	std::wstring FsGetFileVersion(LPCWSTR lpszFilePath);//获取PE文件的文件版本号,必须是PE文件
};
