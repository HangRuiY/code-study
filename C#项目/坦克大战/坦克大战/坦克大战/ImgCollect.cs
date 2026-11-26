using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class ImgCollect
    {
        public static Image wall = Image.FromFile(Application.StartupPath + "\\Images\\wall.jpg");
        public static Image steel = Image.FromFile(Application.StartupPath + "\\Images\\steel.png");
        public static Image boss = Image.FromFile(Application.StartupPath + "\\Images\\boss.jpg");

        public static Bitmap myTankup = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\MyTankUp.png");
        public static Bitmap myTankdown = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\MyTankDown.png");
        public static Bitmap myTankleft = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\MyTankLeft.png");
        public static Bitmap myTankright = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\MyTankRight.png");

        public static Bitmap EnemyTankup1 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GrayUp.png");
        public static Bitmap EnemyTankdown1 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GrayDown.png");
        public static Bitmap EnemyTankleft1 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GrayLeft.png");
        public static Bitmap EnemyTankright1 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GrayRight.png");
        public static Bitmap EnemyTankup2 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GreenUp.png");
        public static Bitmap EnemyTankdown2 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GreenDown.png");
        public static Bitmap EnemyTankleft2 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GreenLeft.png");
        public static Bitmap EnemyTankright2 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\GreenRight.png");
        public static Bitmap EnemyTankup3 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\QuickUp.png");
        public static Bitmap EnemyTankdown3 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\QuickDown.png");
        public static Bitmap EnemyTankleft3 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\QuickLeft.png");
        public static Bitmap EnemyTankright3 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\QuickRight.png");
        public static Bitmap EnemyTankup4 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\SlowUp.png");
        public static Bitmap EnemyTankdown4 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\SlowDown.png");
        public static Bitmap EnemyTankleft4 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\SlowLeft.png");
        public static Bitmap EnemyTankright4 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\SlowRight.png");

        public static Bitmap BulletUp = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\BulletUp.jpg");
        public static Bitmap BulletDown = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\BulletDown.jpg");
        public static Bitmap BulletLeft = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\BulletLeft.jpg");
        public static Bitmap BulletRight = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\BulletRight.jpg");

        public static Bitmap Exp1 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\EXP1.bmp");
        public static Bitmap Exp2 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\EXP2.bmp");
        public static Bitmap Exp3 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\EXP3.bmp");
        public static Bitmap Exp4 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\EXP4.bmp");
        public static Bitmap Exp5 = (Bitmap)Image.FromFile(Application.StartupPath + "\\Images\\EXP5.bmp");
    }
}
