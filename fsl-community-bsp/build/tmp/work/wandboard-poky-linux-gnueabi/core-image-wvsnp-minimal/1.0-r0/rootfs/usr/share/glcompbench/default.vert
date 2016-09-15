attribute vec3 position;
attribute vec2 texcoord;
uniform mat4 projection;
uniform mat4 modelview;
varying vec2 TextureCoord;

void main(void)
{
    TextureCoord = texcoord;
    // Transform the position to clip coordinates
    gl_Position = projection * modelview * vec4(position, 1.0);
}
