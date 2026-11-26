using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    enum Tag
    {
        Mytank,
        EnemyTank
    }
    class Bullet:Movething
    {
        public Tag Tag { get; set; }
        public bool IsDestroy { get; set; }
        public Bullet() { }
        public Bullet(int x, int y, int speed, Direction dir, Tag tag)
        {
            IsMoving = false;
            IsDestroy = false;
            this.X = x;
            this.Y = y;
            this.Speed = speed;
            Bup = ImgCollect.BulletUp;
            Bdown = ImgCollect.BulletDown;
            Bleft = ImgCollect.BulletLeft;
            Bright = ImgCollect.BulletRight;
            Dir = dir;
            this.Tag = tag;
            this.X -= Width / 2;
            this.Y -= Height / 2;
        }
        public override void Draw()
        {
            base.Draw();
        }
        public void MoveCheck()
        {
            if (Dir == Direction.up)
            {
                if (Y + Height / 2 + 3 < 0)
                {
                    IsDestroy = true; return;
                }
            }
            else if (Dir == Direction.down)
            {
                if (Y + Height / 2 - 3 > 450)
                {
                    IsDestroy = true; return;
                }
            }
            else if (Dir == Direction.left)
            {
                if (X + Width / 2 - 3 < 0)
                {
                    IsDestroy = true; return;
                }
            }
            else if (Dir == Direction.right)
            {
                if (X + Width / 2 + 3 > 450)
                {
                    IsDestroy = true; return;
                }
            }
            //是否碰撞
            Rectangle r = GetRectangle();
            r.X = X + Width / 2 - 3;
            r.Y = Y + Height / 2 - 3;
            r.Height = 3;
            r.Width = 3;

            int xExplosion = this.X + Width / 2;
            int yExplosion = this.Y + Height / 2;

            CantMovething wall = null;
            if ((wall = GameobjectMgr.IfmeetWall(r)) != null)//打到墙
            {
                IsDestroy = true;
                GameobjectMgr.DestroyWall(wall);
                GameobjectMgr.CreatExp(xExplosion, yExplosion);
                Sound.PlayBlast();
                return;
            }
            if ( GameobjectMgr.IfmeetSteel(r) != null)//打到铁
            {
                IsDestroy = true;
                GameobjectMgr.CreatExp(xExplosion, yExplosion);
                return;
            }
            if (GameobjectMgr.IfmeetBoss(r) == true)
            {
                GameobjectMgr.CreatExp(xExplosion, yExplosion);
                GameFrameWork.ChangeState();
                Sound.PlayBlast();
                return;
            }
            if (Tag == Tag.Mytank)
            {
                Enemytank e = null;
                if((e=GameobjectMgr.IfmeetEnemyTank(r))!=null)
                {
                    IsDestroy = true;
                    GameobjectMgr.DestroyEnemyTank(e);
                    GameobjectMgr.CreatExp(xExplosion, yExplosion);
                    Sound.PlayBlast();
                    return;
                }
            }
            else if (Tag == Tag.EnemyTank)
            {
                Mytank t = null;
                if((t =GameobjectMgr.IfmeetMytank(r))!=null)
                {
                    IsDestroy=true;
                    GameobjectMgr.CreatExp(xExplosion, yExplosion);
                    t.GetDamage();
                    Sound.PlayHit();
                    return;
                }
            }
        }
        public override void Update()
        {
            MoveCheck();//检查是否超过地图边界
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
            base.Update();
        }
    }
}
