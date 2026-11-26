using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace 坦克大战
{
    class GameobjectMgr
    {
        private static List<CantMovething> walllist = new List<CantMovething>();
        private static List<CantMovething> steellist = new List<CantMovething>();
        private static CantMovething boss = new CantMovething();
        private static Mytank mytank = new Mytank();
        private static List<Enemytank> enemytank = new List<Enemytank>();
        private static List<Bullet> bullets = new List<Bullet>();
        private static List<Explosion> exps = new List<Explosion>();

        private static int EnemyBornSpeed = 100;
        private static int EnemyCount = 100;
        private static Point[] point = new Point[3];
        public static void UpdateMap()
        {
            foreach (CantMovething it in walllist)
            {
                it.Update();
            }
            foreach (CantMovething it in steellist)
            {
                it.Update();
            }
            CheckAndDestroyBullet();
            foreach (Bullet it in bullets)
            {
                it.Update();
            }

            boss.Update();

            mytank.Update();
            
            EnemyBorn();
            foreach(Enemytank it in enemytank)
            {
                it.Update();
            }
            CheckDestroyExp();
            foreach (Explosion it in exps)
            {
                it.Update();
            }
        }
        public static void CreatPosistion()//敌人的生成地点
        {
            point[0].X = 0; point[0].Y = 0;
            point[1].X = 7 * 30; point[1].Y = 0;
            point[2].X = 14 * 30; point[2].Y = 0;
        }
        public static void CreateEnemy1(int x, int y)
        {
            Enemytank tank = new Enemytank(x, y, 2, ImgCollect.EnemyTankup1, ImgCollect.EnemyTankdown1, ImgCollect.EnemyTankleft1, ImgCollect.EnemyTankright1);
            enemytank.Add(tank);
        }
        public static void CreateEnemy2(int x, int y)
        {
            Enemytank tank = new Enemytank(x, y, 2, ImgCollect.EnemyTankup2, ImgCollect.EnemyTankdown2, ImgCollect.EnemyTankleft2, ImgCollect.EnemyTankright2);
            enemytank.Add(tank);
        }
        public static void CreateEnemy3(int x, int y)
        {
            Enemytank tank = new Enemytank(x, y, 3, ImgCollect.EnemyTankup3, ImgCollect.EnemyTankdown3, ImgCollect.EnemyTankleft3, ImgCollect.EnemyTankright3);
            enemytank.Add(tank);
        }
        public static void CreateEnemy4(int x, int y)
        {
            Enemytank tank = new Enemytank(x, y, 1, ImgCollect.EnemyTankup4, ImgCollect.EnemyTankdown4, ImgCollect.EnemyTankleft4, ImgCollect.EnemyTankright4);
            enemytank.Add(tank);
        }
        public static void EnemyBorn()//生成敌人
        {
            EnemyCount++;
            if (EnemyCount < EnemyBornSpeed) return;
            //生成敌人
            Random r = new Random();
            int index = r.Next(0,3);
            Point p = point[index];
            int enemytype = r.Next(1, 5);
            switch (enemytype)
            {
                case 1:
                    CreateEnemy1(p.X, p.Y);
                    break;
                case 2:
                    CreateEnemy2(p.X, p.Y);
                    break; 
                case 3:
                    CreateEnemy3(p.X, p.Y);
                    break;
                case 4:
                    CreateEnemy4(p.X, p.Y);
                    break;
            }
            EnemyCount = 0;
            Sound.PlayAdd();
        }
        public static void CreatMap()
        {
            CreatWall(1, 1, 5, walllist, ImgCollect.wall);
            CreatWall(3, 1, 5, walllist, ImgCollect.wall);
            CreatWall(5, 1, 4, walllist, ImgCollect.wall);
            CreatWall(7, 1, 3, walllist, ImgCollect.wall);
            CreatWall(9, 1, 4, walllist, ImgCollect.wall);
            CreatWall(11, 1, 5, walllist, ImgCollect.wall);
            CreatWall(13, 1, 5, walllist, ImgCollect.wall);
            CreatWall(2, 7, 1, walllist, ImgCollect.wall);
            CreatWall(3, 7, 1, walllist, ImgCollect.wall);
            CreatWall(4, 7, 1, walllist, ImgCollect.wall);
            CreatWall(6, 7, 1, walllist, ImgCollect.wall);
            CreatWall(7, 6, 2, walllist, ImgCollect.wall);
            CreatWall(8, 7, 1, walllist, ImgCollect.wall);
            CreatWall(10, 7, 1, walllist, ImgCollect.wall);
            CreatWall(11, 7, 1, walllist, ImgCollect.wall);
            CreatWall(12, 7, 1, walllist, ImgCollect.wall);
            CreatWall(1, 9, 5, walllist, ImgCollect.wall);
            CreatWall(3, 9, 5, walllist, ImgCollect.wall);
            CreatWall(5, 9, 3, walllist, ImgCollect.wall);
            CreatWall(6, 10, 1, walllist, ImgCollect.wall);
            CreatWall(7, 10, 2, walllist, ImgCollect.wall);
            CreatWall(8, 10, 1, walllist, ImgCollect.wall);
            CreatWall(9, 9, 3, walllist, ImgCollect.wall);
            CreatWall(11, 9, 5, walllist, ImgCollect.wall);
            CreatWall(13, 9, 5, walllist, ImgCollect.wall);
            CreatWall(6, 13, 2, walllist, ImgCollect.wall);
            CreatWall(7, 13, 1, walllist, ImgCollect.wall);
            CreatWall(8, 13, 2, walllist, ImgCollect.wall);

            CreatWall(7, 5, 1, steellist, ImgCollect.steel);
            CreatWall(0, 7, 1, steellist, ImgCollect.steel);
            CreatWall(14, 7, 1, steellist, ImgCollect.steel);

            CreatBoss(7, 14, ImgCollect.boss);
        }
        public static void CreatWall(int x, int y, int count, List<CantMovething> list, Image img)
        {
            int X = x * 30; int Y = y * 30;
            for (int i = Y; i < Y + count * 30; i += 15)
            {
                CantMovething cmt1 = new CantMovething(X, i, img);
                CantMovething cmt2 = new CantMovething(X + 15, i, img);
                list.Add(cmt1);
                list.Add(cmt2);
            }
        }
        public static void CreatBoss(int x,int y,Image img)
        {
            int X = x * 30; int Y = y * 30;
            boss = new CantMovething(X,Y,img);
        }
        public static void CreatMytank()
        {
            int x = 5*30;
            int y =14*30;
            mytank = new Mytank(x, y, 2);
        }
        public static CantMovething IfmeetWall(Rectangle r)//碰到红砖
        {
            foreach(CantMovething it in walllist)
            {
                if (it.GetRectangle().IntersectsWith(r))
                {
                    return it;
                }
            }
            return null;
        }
        public static CantMovething IfmeetSteel(Rectangle r)//碰到铁块
        {
            foreach (CantMovething it in steellist)
            {
                if (it.GetRectangle().IntersectsWith(r))
                {
                    return it;
                }
            }
            return null;
        }
        public static bool IfmeetBoss(Rectangle r)
        {
            return boss.GetRectangle().IntersectsWith(r);
        }
        public static void MytankUp(KeyEventArgs e)
        {
            mytank.KeyUp(e);
        }
        public static void MytankDown(KeyEventArgs e)
        {
            mytank.KeyDown(e);
        }
        public static Mytank IfmeetMytank(Rectangle r)
        {
            if (mytank.GetRectangle().IntersectsWith(r))
                return mytank;
            else
                return null;
        }
        public static void CheckAndDestroyBullet()
        {
            List<Bullet> needToDestroy = new List<Bullet>();
            foreach (Bullet bullet in bullets)
            {
                if (bullet.IsDestroy == true)
                {
                    needToDestroy.Add(bullet);
                }
            }
            foreach (Bullet bullet in needToDestroy)
            {
                bullets.Remove(bullet);
            }
        }//检查和消除子弹
        public static void CreatBullet(int x, int y, Direction dir, Tag tag)
        {
            Bullet bullet = new Bullet(x, y, 8, dir, tag);
            bullets.Add(bullet);
        }
        public static void DestroyBullet(Bullet b)
        {
            lock (bullets)
            {
                bullets.Remove(b);
            }
        }
        public static void DestroyWall(CantMovething wall)
        {
            walllist.Remove(wall);
        }
        public static Enemytank IfmeetEnemyTank(Rectangle r)
        {
            foreach(Enemytank it in enemytank)
            {
                if(it.GetRectangle().IntersectsWith(r))
                    return it;
            }
            return null;
        }
        public static void DestroyEnemyTank(Enemytank tank)
        {
            enemytank.Remove(tank);
        }
        public static void CreatExp(int x,int y)
        {
            Explosion e = new Explosion(x,y);
            exps.Add(e);
        }
        public static void CheckDestroyExp()
        {
            List<Explosion> needToDestroy = new List<Explosion>();
            foreach (Explosion it in exps)
            {
                if (it.needDestroy == true)
                {
                    needToDestroy.Add(it);
                }
            }
            foreach (Explosion it in needToDestroy)
            {
                exps.Remove(it);
            }
        }
    }
}
