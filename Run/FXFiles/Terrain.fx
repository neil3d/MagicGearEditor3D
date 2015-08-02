float4x4 matWorldViewPrj;

struct VS_INPUT
{
	float3 pos : POSITION;
	float2 uv	: TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float2 uv : TEXCOORD0;
};

VS_OUTPUT mainVS(VS_INPUT vert)
{
	VS_OUTPUT vsout;
	
	vsout.pos = mul(float4(vert.pos,1),matWorldViewPrj);
	vsout.uv = vert.uv;
	
	return vsout;
}

//--
float4 wirePS() : COLOR
{
	return float4(1,1,1,1);
}

//--
technique DrawWireframe
{
	pass p0
	{
		CullMode = none;
		FillMode = Wireframe;
		VertexShader = compile vs_1_1 mainVS();
		PixelShader = compile ps_2_0 wirePS();
	}
}