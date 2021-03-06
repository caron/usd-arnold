// Copyright (c) 2018 Luma Pictures . All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// 3. All advertising materials mentioning features or use of this software
// must display the following acknowledgement:
// This product includes software developed by the the organization.
//
// 4. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
// EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef HDAI_MATERIAL_H
#define HDAI_MATERIAL_H

#include <pxr/pxr.h>
#include "pxr/imaging/hdAi/api.h"

#include <pxr/imaging/hd/material.h>

#include "pxr/imaging/hdAi/renderDelegate.h"

#include <ai.h>

#include <unordered_map>

PXR_NAMESPACE_OPEN_SCOPE

class HdAiMaterial : public HdMaterial {
public:
    HDAI_API
    HdAiMaterial(HdAiRenderDelegate* delegate, const SdfPath& id);

    ~HdAiMaterial() override = default;

    HDAI_API
    void Sync(
        HdSceneDelegate* sceneDelegate, HdRenderParam* renderParam,
        HdDirtyBits* dirtyBits) override;

    HDAI_API
    HdDirtyBits GetInitialDirtyBitsMask() const override;
    HDAI_API
    void Reload() override;
    HDAI_API
    AtNode* GetSurfaceShader() const;
    HDAI_API
    AtNode* GetDisplacementShader() const;

protected:
    HDAI_API
    AtNode* ReadMaterialNetwork(const HdMaterialNetwork& network);

    HDAI_API
    AtNode* ReadMaterial(const HdMaterialNode& node);

    HDAI_API
    AtString GetLocalNodeName(const SdfPath& path) const;

    std::unordered_map<AtString, AtNode*, AtStringHash> _nodes;
    HdAiRenderDelegate* _delegate;
    AtNode* _surface = nullptr;
    AtNode* _displacement = nullptr;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // HDAI_MATERIAL_H
