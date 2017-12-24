using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABB
{
    class Program
    {
        static void Main(string[] args)
        {
            ABB arbol = new ABB();
            String i = " ";
            while (i != "0")
            {
                Console.WriteLine("1: Insertar elemento.");
                Console.WriteLine("2: Enorden.");
                Console.WriteLine("3: Posorden.");
                Console.WriteLine("4: Preorden.");
                Console.WriteLine("5: Salir.");
                Console.Write(">> ");
                i = Console.ReadLine();
                switch(i)
                {
                    case "1":
                        Console.WriteLine("Ingrece una letra");
                        Console.Write(">> ");
                        String j = Console.ReadLine();
                        arbol.add(j);
                        break;
                    case "2":
                        arbol.enorden();
                        break;
                    case "3":
                        arbol.posorden();
                        break;
                    case "4":
                        arbol.preorden();
                        break;
                    default:
                        i = "0";
                        break;
                }
            }
        }
    }
}
