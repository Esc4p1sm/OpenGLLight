#version 330 core
 layout (location = 0) in vec3 position;
 //layout (location = 1) in vec3 color;
 layout (location = 2) in vec2 texcoord;

 //out vec3 ourColor;
 // uniform float value;
// uniform mat4 transform;
 //uniform vec4 ourColor;
  uniform mat4 model;
  uniform mat4 view;
  uniform mat4 projection;
  out vec2 TexCoord;

  void main()
  {//справа-налево!
  gl_Position = projection*view*model*vec4(position, 1.0);
  //ourColor=color;
  TexCoord=vec2(texcoord.x,1-texcoord.y);
  }