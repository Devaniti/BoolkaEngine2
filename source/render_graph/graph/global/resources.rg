Resource IndexBuffer {
	Type Buffer
	Size IndexBufferSize
}

Resource VertexBuffer {
	Type Buffer
	Format R16_UINT
	Size VertexBufferSize
}

Resource Tex1D_1 {
	Type Texture1D
	Format R32_FLOAT
	Resolution Resulution1D
	OptimizedClearValue ConstBlack
	SliceCount ConstOne
}

Resource Tex1D_2 {
	Type Texture1D
	Format R16G16B16A16_FLOAT
	Resolution Resulution1D
}

Resource Tex2D_1 {
	Type Texture2D
	Format D32_FLOAT
	Resolution Resulution2D
	OptimizedClearValue ConstBlack
	SliceCount ConstOne
}

Resource Tex2D_2 {
	Type Texture2D
	Format R16G16_FLOAT
	Resolution Resulution2D
}

Resource Tex3D_1 {
	Type Texture3D
	Format R8G8B8A8_UNORM
	Resolution Resulution3D
	OptimizedClearValue ConstBlack
}

Resource Tex3D_2 {
	Type Texture3D
	Format R32_FLOAT
	Resolution Resulution3D
}
