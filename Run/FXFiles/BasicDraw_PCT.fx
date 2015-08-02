
texture texDiffuse;

struct VS_INPUT
{
	float3 pos : POSITION;
	float4 color : COLOR;
	float2 uv	: TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 pos : POSITION;
	float4 color : COLOR0;
	float2 uv	: TEXCOORD0;
};

VS_OUTPUT my_vs(VS_INPUT vert)
{
	VS_OUTPUT vsout;
	
	vsout.pos = float4(vert.pos, 1);
	vsout.color = vert.color;
	vsout.uv = vert.uv;
	
	return vsout;
}

//--
sampler sDiffuse = sampler_state
{
	Texture = <texDiffuse>;
	MipFilter = LINEAR;
    MinFilter = LINEAR;
    MagFilter = LINEAR;
};

float4 my_ps(float4 color : COLOR0,
			 float2 uv : TEXCOORD0 ) : COLOR
{
	return color * tex2D(sDiffuse, uv);
}

//--
technique my_tech
{
	pass p0
	{
		ZEnable = false;
		CullMode = none;
		
		VertexShader = compile vs_1_1 my_vs();
		PixelShader = compile ps_1_1 my_ps();
	}
}
