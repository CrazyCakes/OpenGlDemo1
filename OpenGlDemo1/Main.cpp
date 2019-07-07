#include<gl/GLUT.H>
void myFirstOpenGl(int argc, char *argv[]);
const int win_w = 700, win_h = 700;
GLfloat modelview_matrix[16];
GLfloat edefault_matrix[16];
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
	// ǰ����Χ����.....
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

}
void Initial(void)//��ʼ������ 
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
	//glBitmap();*/
	glFlush();//���OpenGL���������ǿ��ִ���������������OpenGL����
}
int main(int argc, char * argv[])//����ʹ��glut�⺯�����д��ڹ���
{
	myFirstOpenGl( argc, argv);
	return 0;
}
// ��ʼ������
void myFirstOpenGl(int argc, char *argv[])
{

	glutInit(&argc, argv);//ʹ��glut����Ҫ���г�ʼ��
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//�趨������ʾģʽ����ɫģ�ͺͻ��棬������RGB��ɫģ�ͺ͵�����
	glutInitWindowPosition(100, 100);//�趨���ڵĳ�ʼλ�ã���Ļ���Ͻ�Ϊԭ�㣬��λΪ����
	glutInitWindowSize(400, 400);//�趨���ڵĴ�С
	glutCreateWindow("��һ��OpenGL���򡪡�����");//����һ�����ڣ������Ǵ��ڱ�����
	glutDisplayFunc(&myDisplay);//��myDisplayָ��Ϊ��ǰ���ڵ���ʾ���ݺ���
	Initial();
	glutMainLoop();//ʹ���ڿ������������ʹ��ʾ�ص�������ʼ����

}