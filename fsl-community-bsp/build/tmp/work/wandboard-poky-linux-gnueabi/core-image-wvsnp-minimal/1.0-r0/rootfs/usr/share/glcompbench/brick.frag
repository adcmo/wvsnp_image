uniform vec2 BrickSize;
uniform vec2 BrickPct;

uniform sampler2D Texture0;
varying vec2 TextureCoord;

varying vec4 vertex_position;
varying vec4 light_position;

void main()
{
    vec4 texel = texture2D(Texture0, TextureCoord);
    vec2 position = vertex_position.xy/BrickSize;
    if (fract(position.y * 0.5) > 0.5)
    {
        position.x += 0.5;
    }
    position = fract(position);
    vec2 one = vec2(1.0, 1.0);
    vec2 whereami = smoothstep(BrickPct, one, position);
    vec3 vertex_normal = vec3(0.0, 0.0, 1.0);
    if (whereami.x > 0.0 && whereami.x < 0.5)
        vertex_normal.x = (2.0 * pow(whereami.x, 2.0)) + 0.1;
    else if (whereami.x > 0.0 && whereami.x < 1.0)
        vertex_normal.x = (2.0 * pow((whereami.x - 1.0), 2.0)) - 0.1;
    if (whereami.y > 0.0 && whereami.y < 0.5)
        vertex_normal.y = (2.0 * pow(whereami.y, 2.0)) + 0.1;
    else if (whereami.y > 0.0 && whereami.y < 1.0)
        vertex_normal.y = (2.0 * pow((whereami.y - 1.0), 2.0)) - 0.1;
    vec4 lightAmbient = vec4(0.0, 0.0, 0.0, 1.0);
    vec4 lightDiffuse = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);
    vec4 matAmbient = vec4(0.1, 0.1, 0.1, 1.0);
    vec4 matDiffuse = vec4(texel.xyz, 0.5);
    vec4 matSpecular = vec4(1.0, 1.0, 1.0, 1.0);
    float matShininess = 10.0;
    vec3 eye_direction = normalize(-vertex_position.xyz);
    vec3 light_direction = normalize(light_position.xyz);
    vec3 normalized_normal = normalize(vertex_normal);
    vec3 reflection = reflect(-light_direction, normalized_normal);
    float specularTerm = pow(max(0.0, dot(reflection, eye_direction)), matShininess);
    float diffuseTerm = max(0.0, dot(normalized_normal, light_direction));
    vec4 specular = (lightSpecular * matSpecular);
    vec4 ambient = (lightAmbient * matAmbient);
    vec4 diffuse = (lightDiffuse * matDiffuse);
    gl_FragColor = (specular * specularTerm) + ambient + (diffuse * diffuseTerm);
}
