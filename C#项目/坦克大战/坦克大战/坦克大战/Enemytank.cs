using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class Enemytank:Movething
    {
        public int ChangeSpped { get; set; }
        public int ChangeCount = 0;
        public int AttackSpeed { get; set; }
        public int count = 0;
        public Random r = new Random();
        public Enemytank(int x, int y, int speed,Bitmap up,Bitmap down,Bitmap left,Bitmap right)
        {
            IsMoving = true;
            this.X = x;
            this.Y = y;
            this.Speed = speed;
            Bup = up;
            Bdown = down;
            Bleft = left;
            Bright = right;
            Dir = Direction.down;
            AttackSpeed = 90;
            ChangeSpped = 120;
        }
        public void ChangeDir()
        {
            while (true)
            {
                Direction dir = (Direction)r.Next(0, 4);
                if (dir == Dir)
                {
                    continue;
                }
                else
                {
                    Dir = dir;
                    break;
                }
            }
            MoveCheck();//防止调转方向后还碰壁
        }
        public void MoveCheck()
        {
            if (Dir == Direction.up)
            {
                if (Y - Speed < 0)
                {
                    ChangeDir();
                    return;
                }
            }
            else if (Dir == Direction.down)
            {
                if (Y + Speed + Height > 450)
                {
                    ChangeDir();
                    return;
                }
            }
            else if (Dir == Direction.right)
            {
                if (X + Speed + Width > 450)
                {
                    ChangeDir();
                    return;
                }
            }
            else if (Dir == Direction.left)
            {
                if (X - Speed < 0)
                {
                    ChangeDir();
                    return;
                }
            }
            //是否碰到方块，或boss
            Rectangle r = GetRectangle();
            //通过下一步的矩形位置 判断是否可以移动
            switch (Dir)
            {
                case Direction.up:
                    r.Y -= Speed;
                    break;
                case Direction.down:
                    r.Y += Speed;
                    break;
                case Direction.left:
                    r.X -= Speed;
                    break;
                case Direction.right:
                    r.X += Speed;
                    break;
            }
            if (GameobjectMgr.IfmeetWall(r) != null || GameobjectMgr.IfmeetSteel(r) != null || GameobjectMgr.IfmeetBoss(r) == true)
            {
                ChangeDir();
                return;
            }
        }
        public override void Update()
        {
            MoveCheck();//检查是否超过地图边界
            if (IsMoving == true)
            {
                switch (Dir)
                {
                    case Direction.up:
                        Y -= Speed;
                        break;
                    case Direction.down:
                        Y += Speed;
                        break;
                    case Direction.right:
                        X += Speed;
                        break;
                    case Direction.left:
                        X -= Speed;
                        break;
                }
            }
            AttackCheck();//是否需要攻击
            ChangeDirction();
            base.Update();
        }
        public void ChangeDirction()
        {
            ChangeCount++;
            if (ChangeCount < ChangeSpped) return;
            ChangeDir();
            ChangeCount = 0;
        }
        public void AttackCheck()
        {
            count++;
            if (count < AttackSpeed) return;
            Attack();
            count = 0;
        }
        public void Attack()
        {
            int x = X; int y = Y;
            switch (Dir)
            {
                case Direction.up:
                    x += Width / 2;
                    break;
                case Direction.down:
                    x += Width / 2;
                    y += Height;
                    break;
                case Direction.left:
                    y += Height / 2;
                    break;
                case Direction.right:
                    x += Width;
                    y += Height / 2;
                    break;
            }
            GameobjectMgr.CreatBullet(x, y, Dir, Tag.EnemyTank);
        }
    }
}
