float4x4 matWorldViewPrj;

struct VS_INPUT
{
	float3 pos : POSITION;
	float4 color : COLOR;
};

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float4 color : COLOR0;
};

VS_OUTPUT my_vs(VS_INPUT vert)
{
	VS_OUTPUT vsout;
	
	vsout.pos = mul(float4(vert.pos,1),matWorldViewPrj);
	vsout.color = vert.color;
	
	return vsout;
}

//--
float4 my_ps(float4 color : COLOR0) : COLOR
{
	return color;
}

//--
technique my_tech
{
	pass p0
	{
		CullMode = none;
		
		VertexShader = compile vs_1_1 my_vs();
		PixelShader = compile ps_2_0 my_ps();
	}
}
