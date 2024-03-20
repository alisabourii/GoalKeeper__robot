using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Media;
using System.Collections;
using System.IO.Ports;

namespace Akili_kale
{
    public partial class Form1 : Form
    {
        string playerName = "";

        SoundPlayer sound = new SoundPlayer(@"H:\C#\Akili_kale_form\sesler\sonuc.wav");
        
        private string puan;
        

        public Form1()
        {
            InitializeComponent();
            serialPort1.PortName = "COM3";
            serialPort1.BaudRate = 9600;
            serialPort1.Parity = Parity.None;
            serialPort1.DataBits = 8;
            serialPort1.StopBits = StopBits.One;
            serialPort1.Handshake = Handshake.None;
            serialPort1.Open();

        }
        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (serialPort1.IsOpen == true)
                serialPort1.Close();
        }


        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.Write("1");
            
        }

        private void button2_Click(object sender, EventArgs e)
        {
            playerName = textBox1.Text;
        }

        byte index=1;
        
        Dictionary<string, int> score = new Dictionary<string, int>();
        private void button3_Click(object sender, EventArgs e)
        {
            son.Play();
            listBox1.Items.Add(index+"."+playerName+" : ");
            listBox2.Items.Add(puan);
            index++;
            textBox1.Clear();

            //       3.ListBoxda değer yazmak
            listBox3.Items.Clear();
            score.Add(playerName, int.Parse(puan));
            var sortedDict = from entry in score orderby entry.Value ascending select entry;
            var sonuc = sortedDict.Reverse();

            foreach (KeyValuePair<string, int> ele1 in sonuc)
            {
                listBox3.Items.Add(ele1.Key+":"+ ele1.Value);
            }

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            puan = serialPort1.ReadLine();
        }
    }
}
