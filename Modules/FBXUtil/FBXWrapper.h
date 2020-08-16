/*
	FBX�Ĺ����࣬�����FBX��һϵ�в������з�װ
*/

#pragma once

#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "../Common/ResLoadCommon.h"
#include "../Common/Vertex.h"

GRPAppBegin
class FBXWrapper
{
public:
	FBXWrapper();
	~FBXWrapper();

	/*
		����
	*/
	static FBXWrapper* Instance();
	ResLoadStatus LoadScene(std::string file_name, std::vector<Vertex>* p_out_vertex_vectors);
private:
	/*
		��ʼ��
	*/
	void Init();
private:
	FbxManager* m_manager;
	FbxIOSettings* m_io_settings;

	static FBXWrapper* m_instance;

	std::unordered_map<std::string, FbxScene*> m_loaded_scenes;
};

#define FBXWrapperInstance FBXWrapper::Instance()
GRPAppEnd