using PMathDotnet;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DotnetTestConsole
{
    class MainApp
    {
        static void Main(string[] args)
        {
            Vector2i v = new PMathDotnet.Vector2i(3, 5);
            var e0 = Vector2i.E0;
            var v1 = v + e0;
            Console.WriteLine(v1);
        }
    }
}
