Resource ZBuffer {
	Type Texture2D
	Resolution RenderResolution
	Format D32_FLOAT
}

Resource GBufferA {
	Type Texture2D
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource GBufferB {
	Type Texture2D
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource LightBuffer {
	Type Texture2D
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource UpscaleOutput {
	Type Texture2D
	Resolution UpscaleResolution
	Format R16G16B16A16_FLOAT
}

Resource DisplayOutput {
	Type Texture2D
	Resolution OutputResolution
	Format R16G16B16A16_FLOAT
}
