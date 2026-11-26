using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class Mytank : Movething
    {
        public Mytank() { }
        private int ox;
        private int oy;
        public int Hp { get; set; }
        public Mytank(int x,int y,int speed)
        {
            IsMoving = false;
            this.X = x;
            this.Y = y;
            this.Speed = speed;
            Bup = ImgCollect.myTankup;
            Bdown = ImgCollect.myTankdown;
            Bleft = ImgCollect.myTankleft;
            Bright = ImgCollect.myTankright;
            Dir = Direction.up;
            Hp = 4;
            ox = x; oy = y;
        }
        public void GetDamage()
        {
            Hp -= 1;
            if (Hp <= 0)
            {
                X = ox;
                Y = oy;
                Hp = 4;  
            }
        }
        public void MoveCheck()
        {
            if(Dir == Direction.up)
            {
                if (Y - Speed < 0)
                {
                    IsMoving = false;
                    return;
                }
            }
            else if (Dir == Direction.down)
            {
                if (Y + Speed + Height > 450)
                {
                    IsMoving = false;
                    return;
                }
            }
            else if (Dir == Direction.right)
            {
                if (X + Speed +Width >450)
                {
                    IsMoving = false;
                    return;
                }
            }
            else if (Dir == Direction.left)
            {
                if (X - Speed < 0)
                {
                    IsMoving = false;
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
                IsMoving = false;
                return;
            }
        }
        public override void Update()
        {
            MoveCheck();//检查是否超过地图边界
            if(IsMoving == true)
            {
                switch (Dir)
                {
                    case Direction.up:
                        Y-=Speed;
                        break;
                    case Direction.down:
                        Y+=Speed;
                        break;
                    case Direction.right:
                        X+=Speed;
                        break;
                    case Direction.left:
                        X-=Speed;
                        break;
                }
            }
            base.Update();
        }
        public void KeyUp(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W:
                    IsMoving = false;
                    break;
                case Keys.S:
                    IsMoving = false;
                    break;
                case Keys.D:
                    IsMoving = false;
                    break;
                case Keys.A:
                    IsMoving = false;
                    break;
            }
        }
        public void KeyDown(KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.W:
                    this.Dir = Direction.up;
                    IsMoving = true;
                    break;
                case Keys.S:
                    this.Dir = Direction.down;
                    IsMoving = true;
                    break;
                case Keys.D:
                    this.Dir = Direction.right;
                    IsMoving = true;
                    break;
                case Keys.A:
                    this.Dir = Direction.left; 
                    IsMoving = true;
                    break;
                case Keys.J:
                    //发射子弹
                    Attack();  
                    Sound.PlayFire();
                    break;
            }
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
            GameobjectMgr.CreatBullet(x, y, Dir, Tag.Mytank);
        }
       
    }
}
