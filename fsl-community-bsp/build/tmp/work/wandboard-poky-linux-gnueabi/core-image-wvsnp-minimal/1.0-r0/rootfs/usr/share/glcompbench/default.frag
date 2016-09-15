uniform sampler2D Texture0;
varying vec2 TextureCoord;

void main(void)
{
    float alpha = 1.0 - alpha_bias;
    vec4 texel = texture2D(Texture0, TextureCoord);
    gl_FragColor = vec4(texel.xyz, alpha);
}
