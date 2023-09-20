RenderTargetsConfig Default {
    RenderTargets [{
        Format R8G8B8A8_UNORM
        BlendEnable True
        SrcBlend BLEND_SRC_ALPHA
        DestBlend BLEND_INV_SRC_ALPHA
        BlendOp BLEND_OP_ADD
        SrcBlendAlpha BLEND_ZERO
        DestBlendAlpha BLEND_ZERO
        BlendOpAlpha BLEND_OP_ADD
        WriteMask MASK_RED | MASK_GREEN | MASK_BLUE | MASK_ALPHA
    }]
}

DepthStencilConfig Default {
    Format D32_FLOAT
    DepthEnable True
    DepthWriteEnable True
    DepthFunc EQUAL
    StencilEnable False
    StencilReadMask 0xFF
    StencilWriteMask 0xFF
}

RasterizerStateConfig Default {
    FillMode Solid
    CullMode Back
    FrontFacing CCW
    DepthBias 0
    DepthBiasClamp 0.0f
    SlopeScaledDepthBias 0.0f
    DepthClipEnable True
    ConservativeRaster False
}

InputLayoutConfig Default {
    InputElements [{
        Name POSITION
        Format R16G16B16A16_FLOAT
        Slot 0
        Classification PER_VERTEX
    }]
}

GraphicPSO TestTrianglePSO {
    AS TestTriangleAS
    MS TestTriangleMS
    PS TestTrianglePS
    RenderTargets Default
    DepthStencil Default
    RasterizerState Default
    InputLayout Default
    PrimitiveTopology TRIANGLE
}
