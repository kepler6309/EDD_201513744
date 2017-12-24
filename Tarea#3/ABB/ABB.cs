using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABB
{
    public class ABB
    {
        private class node
        {
            public node(String data_)
            {
                data = data_;
                left = null;
                right = null;
            }
            private node left;
            public node Left
            {
                get { return left;}
                set { left = value; }
            }
            private node right;
            public node Right
            {
                get { return right; }
                set { right = value; }
            }
            private String data;
            public String Data
            {
                get { return data; }
                set { data = value; }
            }
        }

        private node root;

        public void add(String data)
        {
            root = add(root, data);
        }

        node add(node aux, String data)
        {
            if (aux == null)
            {
                aux = new node(data);
                return aux;
            }
            else if(String.Compare(data,aux.Data)<0)
            {
                aux.Left = add(aux.Left, data);                 
                return aux;
            }
            else if (String.Compare(data, aux.Data) > 0)
            {
                aux.Right = add(aux.Right, data);
                return aux;
            }
            else
            {
                return aux;
            }
        }

        public void enorden()
        {
            Console.Write("[ ");
            enorden(root);
            Console.Write("]");
            Console.WriteLine();
        }
        public void posorden()
        {
            Console.Write("[ ");
            posorden(root);
            Console.Write("]");
            Console.WriteLine();
        }
        public void preorden()
        {
            Console.Write("[ ");
            preorden(root);
            Console.Write("]");
            Console.WriteLine();
        }

        void enorden(node aux)
        {            
            if (aux != null)
            {
                enorden(aux.Left);
                Console.Write(aux.Data+" ");
                enorden(aux.Right);
            }
        }
        void posorden(node aux)
        {
            if (aux != null)
            {
                posorden(aux.Left);
                posorden(aux.Right);
                Console.Write(aux.Data + " ");                
            }            
        }
        void preorden(node aux)
        {
            if (aux != null)
            {
                Console.Write(aux.Data + " ");
                preorden(aux.Left);                
                preorden(aux.Right);
            }
        }
    }
}
