#include "FileFormat.hpp"
#include "NBE.hpp"
#include "Lua.hpp"
#include "CPP.hpp"
#include "../util/filesys.hpp"

FileFormat *getFromType(FileFormatType id, EditorState *st)
{
	switch (id) {
	case FILE_FORMAT_NBE:
		return new NBEFileFormat(st);
	case FILE_FORMAT_LUA:
		return new LuaFileFormat(st);
	case FILE_FORMAT_CPP:
		return new CPPFileFormat(st);
	}
	return NULL;
}


FileFormat *getFromExt(std::string path, EditorState *st)
{
	std::string ext = extFromFilename(path);

	std::cerr << "Ext is " << ext.c_str() << std::endl;

	if (ext == "nbe")
		return new NBEFileFormat(st);
	else if (ext == "lua")
		return new LuaFileFormat(st);
	else if (ext == "cpp")
		return new CPPFileFormat(st);
	else
		return NULL;
}
