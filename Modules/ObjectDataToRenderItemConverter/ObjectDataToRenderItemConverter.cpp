#include "ObjectDataToRenderItemConverter.h"
#include "../Common/RenderItems.h"
#include "../Common/GeometryDefines.h"

GRPAppBegin

ObjectDataToRenderItemConverter::ObjectDataToRenderItemConverter(std::vector<std::unique_ptr<ObjectData>>* object_data)
	: m_ptr_objs_data(object_data)
{

}

std::vector<RenderItem*> ObjectDataToRenderItemConverter::Result()
{
	std::vector<RenderItem*> res;
	for(int i=0; i<m_ptr_objs_data->size(); ++i)
	{
		auto render_item = std::make_unique<RenderItem>();
		render_item->ObjCBIndex = i;
		render_item->IndexCount = m_ptr_objs_data->at(i)->Mesh.Indices.size();
		res.push_back(render_item.release());
	}
	return res;
}

ObjectDataToRenderItemConverter::~ObjectDataToRenderItemConverter()
{

}

GRPAppEnd