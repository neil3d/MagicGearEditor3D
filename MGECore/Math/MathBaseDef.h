#pragma once

namespace MagicGear
{
	inline float _DegToRad(float a) { return a*0.01745329252f;};
	inline float _RadToDeg(float a) { return a*57.29577951f;};

	typedef D3DXVECTOR2		Vector2;
	typedef D3DXVECTOR3		Vector3;
	typedef D3DXVECTOR4		Vector4;
	typedef D3DXQUATERNION	Quaternion;
	typedef D3DXMATRIX		Matrix4;

	inline Vector3 operator * (const Vector3& v,const Matrix4& m)
	{
		return Vector3(v.x*m._11+v.y*m._21+v.z*m._31+m._41,
			v.x*m._12+v.y*m._22+v.z*m._32+m._42,
			v.x*m._13+v.y*m._23+v.z*m._33+m._43);
	}

	inline void matLoadIdentity(Matrix4& mat)
	{
		D3DXMatrixIdentity(&mat);
	}
}//namespace MagicGear