static const char *stock_xmb = 
"struct input\n"
"{\n"
"  float time;\n"
"};\n"

"float iqhash(float n)\n"
"{\n"
"return fract(sin(n)*43758.5453);\n"
"}\n"

"float noise(float3 x)\n"
"{\n"
"float3 p = floor(x);\n"
"float3 f = frac(x);\n"
"f = f * f * (3.0 - 2.0 * f);\n"
"float n = p.x + p.y * 57.0 + 113.0 * p.z;\n"
"return lerp(lerp(lerp(iqhash(n+0.0), iqhash(n+1.0), f.x),\n"
"lerp(iqhash(n+57.0), iqhash(n+58.0), f.x), f.y),\n"
"lerp(lerp(iqhash(n+113.0), iqhash(n+114.0), f.x),\n"
"lerp(iqhash(n+170.0), iqhash(n+171.0), f.x), f.y), f.z);\n"
"}\n"

"void main_vertex\n"
"(\n"
"	float4 position	: POSITION,\n"
"	float4 color	: COLOR,\n"
"	float2 texCoord : TEXCOORD0,\n"

"    uniform input IN,\n"

"	out float4 oPosition : POSITION,\n"
"	out float4 oColor    : COLOR,\n"
"	out float2 otexCoord : TEXCOORD\n"
")\n"
"{\n"
"float3 v = position.xyz;\n"
"float3 v2 = v;\n"
"v2.x = v2.x + IN.time / 2.0;\n"
"v2.z = v.z * 3.0;\n"
"v.y = -cos((v.x + v.z / 3.0 + IN.time) * 2.0) / 10.0 - noise(v2.xyz) / 3.0;\n"
"	oPosition = float4(v, 1.0);\n"
"	oColor = color;\n"
"	otexCoord = texCoord;\n"
"}\n"

"struct output\n"
"{\n"
"  float4 color    : COLOR;\n"
"};\n"

"output main_fragment(uniform input IN) \n"
"{\n"
"   output OUT;\n"
"   OUT.color = float4(1.0, 1.0, 1.0, 0.05);\n"
"   return OUT;\n"
"}\n"