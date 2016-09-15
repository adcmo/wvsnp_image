uniform mat4 modelview;
uniform mat4 projection;
uniform vec4 LightPosition;

attribute vec3 position;
attribute vec2 texcoord;

varying vec4 vertex_position;
varying vec4 light_position;
varying vec2 TextureCoord;

void main()
{
    vec4 curVertex = vec4(position.x, position.y, position.z, 1.0);
    gl_Position = projection * modelview * curVertex;
    TextureCoord = texcoord;
    light_position = modelview * LightPosition;
    vertex_position = modelview * curVertex;
}
