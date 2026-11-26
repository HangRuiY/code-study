using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 坦克大战
{
    class CantMovething:GameObject
    {
        public Image img;
        public Image Img 
        { 
            get
            {
                return img;
            }
            set
            {
                img = value;
                Width = img.Width;
                Height = img.Height;
            }
        }
        public CantMovething() { }
        public CantMovething(int x,int y,Image img)
        {
            this.X = x;
            this.Y = y;
            this.Img = img;
        }
        public override Image GetImage()
        {
            return Img;
        }
    }
}
