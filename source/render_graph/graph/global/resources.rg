Resource Texture2D ZBuffer {
	Resolution RenderResolution
	Format D32_FLOAT
}

Resource Texture2D GBufferA {
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource Texture2D GBufferB {
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource Texture2D LightBuffer {
	Resolution RenderResolution
	Format R16G16B16A16_FLOAT
}

Resource Texture2D UpscaleOutput {
	Resolution UpscaleResolution
	Format R16G16B16A16_FLOAT
}

Resource Texture2D DisplayOutput {
	Resolution OutputResolution
	Format R16G16B16A16_FLOAT
}
