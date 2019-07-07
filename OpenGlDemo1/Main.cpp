#include<gl/GLUT.H>
#include<stdio.h>
#include<iostream>
using namespace std;
void myFirstOpenGl(int argc, char *argv[]);
const int win_w = 700, win_h = 700;
GLfloat modelview_matrix[16];
GLfloat default_matrix[16];
GLfloat modelview_z_dis;
GLfloat x_min = .0, x_max = 20.0, y_min = .0, y_max = 20.0, z_min = .0, z_max = 20.0;
void xyz_line(float len)
{
	GLfloat color[] = { .0,.0,.0,1.0 };
	// �������ã�ָ�������ò��ʵ��ĸ��������ɫ
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	// ��ʾһ�����ڶ���һ�����߶��ͼԪ�Ķ���Ŀ�ʼ��ͨ����glEndһ���ã�����֮��ɵ���һЩ����
	glBegin(GL_LINES);
	// ������ɫ
	color[0] = 1.0; color[1] = .0; color[2] = .0;
	// ǰ����Χ����
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glVertex3f(.0, .0, .0);
	glVertex3f(len, .0,.0);
	color[0] = .0; color[1] = 1.0; color[2] = .0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glVertex3f(.0, .0, .0);
	glVertex3f(.0, len, .0);
	color[0] = .0; color[1] = .0; color[2] = 1.0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glVertex3f(.0, .0, .0);
	glVertex3f(.0, .0, len);
	glEnd();
}
void draw()
{
	// ����һ����ɫ����
	GLfloat color[] = { .4f,.4f,.4f,1.0f };
	// ����
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);

	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 30.0);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);

	// ����������߽�����Ҫ��ʲô������������������ģʽ��
	// GL_PROJECTION ͶӰ, GL_MODELVIEW ģ����ͼ, GL_TEXTURE ����
	glMatrixMode(GL_MODELVIEW);
	// ���浱ǰ����
	glPushMatrix();
	glTranslatef(8.0, 5.0, 8.0);
	glutSolidSphere(5., 30, 50);
	glPopMatrix();

	// ����һ�澵��
	color[0] = 1.0;color[1] = 1.0;color[2] = 1.0;color[3] = 1.0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50.0);
	color[0] = .0f;color[1] = .0f;color[2] = .1f;color[3] = 1.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(.0, 20.0, .0);
	glBegin(GL_MODELVIEW);
	glNormal3f(.0, -1.0, .0);
	glVertex3f(.0, .0, .0);
	glVertex3f(20.0, .0, .0);
	glVertex3f(20.0, .0, 20.0);
	glVertex3f(.0, .0, 20.0);
	glEnd();
	// ɾ������
	glPopMatrix();

	// ��������������
	color[0] = .0;color[1] = .0;color[2] = .0;color[3]=1.0;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);

	glBegin(GL_TRIANGLES);
	color[0] = .0f;color[1] = .8f;color[2] = .8f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glNormal3f(1.0, .0, .0);
	glVertex3f(.0, .0, .0);
	glVertex3f(.0, 15.0, .0);
	glVertex3f(.0, .0, 30.0);
	glEnd();

	// ͸������ŵ����в�͸���������ƣ����򲻻��ϣ���������Ȼ���ֻ����������ڵ�֮�����壩
	glDepthMask(GL_FALSE);
	// ����������
	glBegin(GL_TRIANGLES);
	color[0] = 1.0;color[1] = 1.0;color[2] = .0;color[3] = 0.5;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, color);
	glNormal3f(.0, .0, 1.0);
	glVertex3f(.0, .0, .0);
	glVertex3f(10.0, .0, .0);
	glVertex3f(.0, 20.0, .0);
	glEnd();
	glDepthMask(GL_TRUE);

}
// ��ʾ����
void display_func()
{
	static int z = 0;
	std:: cout<< "display:" << z++ << std::endl;
	// ��ʾҪ�����ɫ�����Լ���Ȼ��壬����ʹ�����±�־λ
	// GL_COLOR_BUFFER_BIT:    ��ǰ��д����ɫ����
    // GL_DEPTH_BUFFER_BIT:    ��Ȼ���
	// GL_ACCUM_BUFFER_BIT : �ۻ�����
	// GL_STENCIL_BUFFER_BIT : ģ�建��
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	// ���õ�ǰ����
	glLoadMatrixf(modelview_matrix);

	draw();
	xyz_line(40.0);
	// ����������������ָ�룬��������ɣ��������ʾ����Ļ�ϣ��Ӷ����Ƶ��ˢ�µ��µĻ�����˸����
	glutSwapBuffers();

}
// ��ʼ��opengl
void init()
{
	// ͶӰ�����ʼ��
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0, 1.0, 10.0, 300.0);
	// Ĭ�Ͼ����ʼ��
	glMatrixMode(GL_MODELVIEW);
	// �Ե�ǰ������г�ʼ��
	glLoadIdentity();
	/*����ԭ��
		void gluLookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz);
	�ú�������һ����ͼ���󣬲��뵱ǰ������ˡ�
		��һ��eyex, eyey, eyez ��������������λ��
		�ڶ���centerx, centery, centerz �����ͷ��׼�����������������λ��
		������upx, upy, upz ������ϵķ��������������еķ���
		�����������Ϊ���Լ����Դ���
		��һ�����ݾ����Դ���λ��
		�ڶ������ݾ����۾����������λ��
		���������ͷ������ķ�����Ϊ���������ͷ��ͬһ�����壩*/
	gluLookAt(100.0 + (x_min + x_max)*.5, 100.0 + (y_min + y_max)*.5, 100.0 + (z_min + z_max)*.5,
		(x_min + x_max)*.5, (y_min + y_max)*.5, (z_min + z_max)*.5, .0, .0, 1.0);
	modelview_z_dis= 100.0f * sqrt(3.0f);
	//���������������ȡ��GL_MODELVIEW_MATRIX��Ȼ��洢��mat��������У�������任��
	glGetFloatv(GL_MODELVIEW_MATRIX, default_matrix);
	// ��default������modelview�У�sizeof��ʾ������С
	memcpy(modelview_matrix, default_matrix,sizeof(default_matrix));
	glLoadIdentity();
	// ������ɫ�͹���
	glClearColor(.2f, .2f, .2f, 1.0f);
	glColor4f(.5f, .5f, .5f, 1.0f);
	glShadeModel(GL_SMOOTH);
	
	GLfloat vec4f[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, vec4f);  // ��Դɢ����ɫ������
	glLightfv(GL_LIGHT0, GL_SPECULAR, vec4f); // ��Դ������ɫ������
	vec4f[0] = .1f; vec4f[1] = .1f; vec4f[2] = .1f;
	glLightfv(GL_LIGHT0, GL_AMBIENT, vec4f);  // ��Դ����ǿ�ȣ���ɫ��0.1 ǿ�Ȱ�ɫ��
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // ����Զ�۲��
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);     // ˫�����
	vec4f[0] = .0; vec4f[1] = .0; vec4f[2] = .0;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, vec4f);	// ȫ�ֻ����⣬��ɫ���޹⣩

	vec4f[0] = .0; vec4f[1] = modelview_z_dis; vec4f[2] = .0; vec4f[3] = 1.0;
	glLightfv(GL_LIGHT0, GL_POSITION, vec4f); // λ��ʽ��Դ��λ��������б�Ϸ�
	vec4f[0] = .0; vec4f[1] = .0; vec4f[2] = -1.0;
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, vec4f); // ��Դ���ⷽ��

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_NORMALIZE); // ʹ���Զ��淶��������������֤���ռ������ȷ��
}
/*void Initial(void)//��ʼ������ 
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//��ɫ������ǰ3����RGB�������Alphaֵ����������͸����1.0��ʾ��ȫ��͸��
	glMatrixMode(GL_PROJECTION);//OpenGL������ά��ʽ������ͼ��������Ҫһ��ͶӰ�任����άͼ��ͶӰ����ʾ���Ķ�ά�ռ���
	gluOrtho2D(0.0, 200, 0.0, 150.0);//ָ��ʹ����ͶӰ��һ��x������0~200��y����0~150��Χ�ڵľ�����������ͶӰ����ʾ������

}
void myDisplay(void)//��ʾ�ص�����
{
	xyz_line(40.0);
	/*glClear(GL_COLOR_BUFFER_BIT);//ʹ��glClearColorz��ָ����ֵ�趨��ɫ��������ֵ�����������е�ÿһ����������Ϊ����ɫ
	glColor3f(1.0f, 0.0f, 0.0f);//��ͼ��ɫΪ�ٻ�ɫ
	glRectf(50.0f, 100.0f, 150.0f, 50.0f);//ͼ�ε����꣬����һ�����Ͻ��ڣ�50��100�������½��ڣ�150��50���ľ���
	//glBitmap();
	glFlush();//���OpenGL���������ǿ��ִ���������������OpenGL����
}*/

void reshape_func(int w, int h);
void display_func();
void mouse_click_func(int button, int state, int x, int y);
void mouse_move_func(int x, int y);
void keyboard_func(unsigned char key, int x, int y);
void specialkey_func(int key, int x, int y);
int main(int argc, char * argv[])//����ʹ��glut�⺯�����д��ڹ���
{
	//myFirstOpenGl( argc, argv);
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(win_w, win_h);
	glutInitWindowPosition(300, 0);
	glutCreateWindow("glut test");
	// The callbacks.
	glutReshapeFunc(reshape_func);
	glutDisplayFunc(display_func);
	glutMouseFunc(mouse_click_func);
	glutMotionFunc(mouse_move_func);
	glutKeyboardFunc(keyboard_func);
	glutSpecialFunc(specialkey_func);
	init();
	glutMainLoop();
	return 0;
	return 0;
}
// ���ڴ�С�ı����Ӧ����
void reshape_func(int w, int h)
{
	glViewport(0, h - win_w, win_w, win_h);
}
/* ���������������������ƽ�ơ���ת�����ţ����Ǿ����Ӿ�(����)�����½���
 * �������� glTranslate,glRotate,glScale �����ھֲ������½���(������)
 * Ϊ�˴ﵽ���Ӿ������²�����Ч������Ҫ��������˵���ǰ����
 */
void absolute_translate(GLfloat x, GLfloat y, GLfloat z)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, z);
	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
	glPopMatrix();
}
void absolute_rotate(GLfloat dgree, GLfloat vecx, GLfloat vecy, GLfloat vecz)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(.0, .0, -modelview_z_dis);		// ƽ�ƻ�ȥ��ע��þ�ͺ�����Ҫ��������
	glRotatef(dgree, vecx, vecy, vecz);// ������ת��
	glTranslatef(.0, .0, modelview_z_dis);		// ��ƽ�Ƶ�ԭ��
	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
	glPopMatrix();
}
void absolute_scale(GLfloat factor)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(.0, .0, -modelview_z_dis);		// ƽ�ƻ�ȥ��ע��þ�ͺ�����Ҫ��������
	glScalef(factor, factor, factor);
	glTranslatef(.0, .0, modelview_z_dis);		// ��ƽ�Ƶ�ԭ��
	glMultMatrixf(modelview_matrix); // ʹ�任������˵���ǰ�����������ʺϾ�������Ŀ���
	glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
	glPopMatrix();
}
void absolute_default()
{
	memcpy(modelview_matrix, default_matrix, sizeof(default_matrix));
}

// ���״̬������������������¼����϶��¼�֮��ͨ��
static bool l_button_down = false, r_button_down = false, mid_button_down = false;
static int last_x = -1, last_y = -1;
#define  GLUT_WHEEL_UP		3 // ���ֲ���  
#define  GLUT_WHEEL_DOWN	4
/* ��������ƶ�������϶���ת���м��϶�ƽ�ƣ��Ҽ��ص������ͼ
 */
void mouse_click_func(int button, int state, int x, int y)
{
	y = win_h - y;
	switch (button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN) {
			l_button_down = true;
			last_x = x; last_y = y;
			glutSetCursor(GLUT_CURSOR_CROSSHAIR);
		}
		else {
			l_button_down = false;
			last_x = -1; last_y = -1;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN) {
			mid_button_down = true;
			last_x = x; last_y = y;
			glutSetCursor(GLUT_CURSOR_CYCLE);

		}
		else {
			mid_button_down = false;
			last_x = -1; last_y = -1;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN) {
			r_button_down = true;
			absolute_default();
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			glutPostRedisplay();
		}
		else {
			r_button_down = false;
			glutSetCursor(GLUT_CURSOR_INHERIT);
		}
		break;
	case GLUT_WHEEL_UP:
		if (state == GLUT_UP) {
			absolute_scale(.9f);
			glutPostRedisplay();
		}
		break;
	case GLUT_WHEEL_DOWN:
		if (state == GLUT_UP) {
			absolute_scale(1.1f);
			glutPostRedisplay();
		}
		break;
	}
}
void mouse_move_func(int x, int y)
{
	y = win_h - y;
	if (last_x >= 0 && last_y >= 0 && (last_x != x || last_y != y)) {
		GLfloat deltax = GLfloat(x - last_x), deltay = GLfloat(y - last_y);
		if (mid_button_down) {
			absolute_translate(deltax * .1f, deltay * .1f, .0f);
			glutPostRedisplay();
		}
		else if (l_button_down) {
			GLfloat dis = sqrt(deltax*deltax + deltay * deltay);
			absolute_rotate(dis, -deltay / dis, deltax / dis, .0);
			glutPostRedisplay();
		}
	}
	last_x = x; last_y = y;
}
/* ���̰���
 */
void keyboard_func(unsigned char key, int x, int y)
{
	;
}

/* ��������������¼�����������ת�����Ҽ�����������ת
 */
void specialkey_func(int key, int x, int y)
{
	GLfloat deltax = .0, deltay = .0;
	switch (key) {
	case GLUT_KEY_UP:
		deltay += 1.0;
		break;
	case GLUT_KEY_DOWN:
		deltay -= 1.0;
		break;
	case GLUT_KEY_LEFT:
		deltax -= 1.0;
		break;
	case GLUT_KEY_RIGHT:
		deltax += 1.0;
		break;
	}
	if (abs(deltax) > .0 || abs(deltay) > .0) {
		GLfloat dis = sqrt(deltax*deltax + deltay * deltay);
		absolute_rotate(dis, -deltay / dis, deltax / dis, .0);
		glutPostRedisplay();
	}
}
// ��ʼ������
/*void myFirstOpenGl(int argc, char *argv[])
{

	glutInit(&argc, argv);//ʹ��glut����Ҫ���г�ʼ��
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//�趨������ʾģʽ����ɫģ�ͺͻ��棬������RGB��ɫģ�ͺ͵�����
	glutInitWindowPosition(100, 100);//�趨���ڵĳ�ʼλ�ã���Ļ���Ͻ�Ϊԭ�㣬��λΪ����
	glutInitWindowSize(400, 400);//�趨���ڵĴ�С
	glutCreateWindow("��һ��OpenGL���򡪡�����");//����һ�����ڣ������Ǵ��ڱ�����
	glutDisplayFunc(&myDisplay);//��myDisplayָ��Ϊ��ǰ���ڵ���ʾ���ݺ���
	Initial();
	glutMainLoop();//ʹ���ڿ������������ʹ��ʾ�ص�������ʼ����

}*/