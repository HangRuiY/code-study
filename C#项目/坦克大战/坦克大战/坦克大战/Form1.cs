using System.Runtime.Versioning;
using System.Windows.Forms.PropertyGridInternal;
namespace 坦克大战
{
    public partial class Form1 : Form
    {
        private Thread t;
        public static Graphics windowg;
        private static Bitmap bmp;
        public Form1()//窗体
        {
            InitializeComponent();//窗体初始化
            this.StartPosition = FormStartPosition.CenterScreen;//窗体放到屏幕中间

            windowg = this.CreateGraphics();//给外部一个画布

            bmp = new Bitmap(450, 450);
            Graphics temp = Graphics.FromImage(bmp);
            GameFrameWork.g = temp;
            //线程创建
            t = new Thread(GameMainThread);
            t.IsBackground = true;
            t.Start();
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
        }
        private bool isRun = true;
        private void GameMainThread()
        {
            GameFrameWork.Start();//游戏启动时调用
            while (isRun)
            {
                //涂黑背景
                GameFrameWork.g.Clear(Color.Black);
                GameFrameWork.Update();//游戏更新时调用
                windowg.DrawImage(bmp, 0, 0);
                //休眠 达到60帧
                Thread.Sleep(1000 / 60);
            }
        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            isRun = false;//关闭线程
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            GameobjectMgr.MytankUp(e);
        }
        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            GameobjectMgr.MytankDown(e);
        }
    }
}

