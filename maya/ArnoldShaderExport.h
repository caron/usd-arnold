#ifndef USDMAYA_ARNOLD_SHADER_EXPORT_H
#define USDMAYA_ARNOLD_SHADER_EXPORT_H

#include <pxr/usd/usdAi/aiShaderExport.h>

#include <usdMaya/util.h>

#include <maya/MObject.h>
#include <maya/MDagPath.h>

#include <ai.h>

PXR_NAMESPACE_OPEN_SCOPE

class ArnoldShaderExport : public AiShaderExport {
public:
    ArnoldShaderExport(const UsdStageRefPtr& _stage, const UsdTimeCode& _time_code,
                       bool strip_namespaces, const SdfPath& parent_scope,
                       const UsdMayaUtil::MDagPathMap<SdfPath>& dag_to_usd);
    virtual ~ArnoldShaderExport();

private:
    enum TransformAssignment{
        TRANSFORM_ASSIGNMENT_DISABLE,
        TRANSFORM_ASSIGNMENT_COMMON,
        TRANSFORM_ASSIGNMENT_FULL
    };
    TransformAssignment m_transform_assignment;
    const UsdMayaUtil::MDagPathMap<SdfPath>& m_dag_to_usd;

    void setup_shader(const MDagPath& dg, const SdfPath& path);
public:
    SdfPath export_shading_engine(MObject obj);
    void setup_shaders();

    bool m_strip_namespaces;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif
