using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace ooohost
{
    public partial class Form1 : Form
    {
        private void populate()
        {
            string ConnectionString = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            SqlConnection con = new SqlConnection(ConnectionString);
            con.Open();
            string query = "SELECT * FROM Tb4_Employee";
            SqlDataAdapter da = new SqlDataAdapter(query, con);
            SqlCommandBuilder builder = new SqlCommandBuilder(da);
            var ds = new DataSet();
            da.Fill(ds);
            dataGridView1.DataSource = ds.Tables[0];
            con.Close();
        }
        private object reservedGrid;

#pragma warning disable CS8618 // Non-nullable field must contain a non-null value when exiting constructor. Consider declaring as nullable.
        public Form1()
#pragma warning restore CS8618 // Non-nullable field must contain a non-null value when exiting constructor. Consider declaring as nullable.
        {
            InitializeComponent();
        }



        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label20_Click(object sender, EventArgs e)
        {

        }

        private void label22_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            populate();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {


            string MyConnection2 = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            //Display query  
            string Query = "select * from Tb4_Employee;";
            SqlConnection MyConn2 = new SqlConnection(MyConnection2);
            SqlCommand MyCommand2 = new SqlCommand(Query, MyConn2);
            //  MyConn2.Open();  
            //For offline connection we weill use  MySqlDataAdapter class.  
            SqlDataAdapter MyAdapter = new SqlDataAdapter();
            MyAdapter.SelectCommand = MyCommand2;
            DataTable dTable = new DataTable();
            MyAdapter.Fill(dTable);
            dataGridView1.DataSource = dTable;



        }

        private void button1_Click(object sender, EventArgs e)

        {
            DateTime t;
            t = dateTimePicker1.Value;
            //MessageBox.Show(t.ToString());
            try
            {
                String aa = "";
                if (radioButton1.Checked == true) { aa = "male"; } else { aa = "female"; }
                String str = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";

                String query = "select * from staff_tb1";

                SqlConnection con = new SqlConnection(str);

                SqlCommand cmd = new SqlCommand(query, con);

                con.Open();

                DataSet ds = new DataSet();

                // textBox1.Text = "hello";
                //MessageBox.Show("aa");
                //textBox2.Text = textBox1.Text;
                string a = textBox1.Text;


                con.Close();

                string qury = "INSERT INTO Tb4_Employee VALUES(@a,@b,@c,@d,@name,@e,@f,@g,@h,@ei,@ej,@ek,@el,@em,@ee,@ew,@et,@ey,@eu,@eee)";

                cmd = new SqlCommand(qury, con);
                cmd.Parameters.AddWithValue("@a", comboBox1.Text);
                cmd.Parameters.AddWithValue("@b", textBox1.Text);
                cmd.Parameters.AddWithValue("@c", aa);
                cmd.Parameters.AddWithValue("@name", "NULL");

                cmd.Parameters.AddWithValue("@d", textBox2.Text);
                cmd.Parameters.AddWithValue("@e", textBox3.Text);
                cmd.Parameters.AddWithValue("@f", textBox4.Text);
                cmd.Parameters.AddWithValue("@h", t.ToString());
                cmd.Parameters.AddWithValue("@g", textBox5.Text);
                cmd.Parameters.AddWithValue("@ei", textBox6.Text);
                cmd.Parameters.AddWithValue("@ej", textBox7.Text);
                cmd.Parameters.AddWithValue("@ek", textBox8.Text);
                cmd.Parameters.AddWithValue("@el", textBox9.Text);
                cmd.Parameters.AddWithValue("@eee", comboBox2.Text);
                cmd.Parameters.AddWithValue("@em", textBox10.Text);
                cmd.Parameters.AddWithValue("@en", textBox11.Text);
                cmd.Parameters.AddWithValue("@ew", textBox12.Text);
                cmd.Parameters.AddWithValue("@ee", textBox13.Text);
                cmd.Parameters.AddWithValue("@et", textBox14.Text);
                cmd.Parameters.AddWithValue("@ey", textBox15.Text);
                cmd.Parameters.AddWithValue("@eu", textBox16.Text);


                con.Open();
                cmd.ExecuteNonQuery();
                con.Close();

                MessageBox.Show(" DATA SuccessFully INSERTED!");









            }
            catch (Exception es)
            {


                MessageBox.Show(es.Message);







            }

        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();
        }

        private void button7_Click(object sender, EventArgs e)
        {



        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox17_TextChanged(object sender, EventArgs e)
        {

        }

        private void button8_Click(object sender, EventArgs e)

        {



        }

        private void textBox19_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox17_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void label26_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click(object sender, EventArgs e)
        {


            {
                MessageBox.Show("Invalid username or password");

                SqlConnection con = new SqlConnection(@"Data Source=USER;Initial Catalog=admin;Integrated Security=True"); // making connection   
                SqlDataAdapter sda = new SqlDataAdapter("SELECT COUNT(*) FROM login WHERE username='" + textBox1.Text + "' AND password='" + textBox2.Text + "'", con);
                /* in above line the program is selecting the whole data from table and the matching it with the user name and password provided by user. */
                DataTable dt = new DataTable(); //this is creating a virtual table  
                sda.Fill(dt);
                if (dt.Rows[0][0].ToString() == "1")
                {
                    /* I have made a new page called home page. If the user is successfully authenticated then the form will be moved to the next form */
                    this.Hide();
                    new login().Show();
                }
                else
                {
                    MessageBox.Show("Invalid username or password");
                }
            }





        }






        private void button8_Click_1(object sender, EventArgs e)
        {
            System.Windows.Forms.Application.Exit();


        }

        private void textBox18_TextChanged(object sender, EventArgs e)
        {

        }

        private void tabPage4_Click(object sender, EventArgs e)
        {

        }

        private void button10_Click(object sender, EventArgs e)
        {
            string message = "Do you want to close this window?";
            string title = "Close Window";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                this.Close();
            }
            else
            {
                // Do something  
            }
        }

        private void textBox20_TextChanged(object sender, EventArgs e)
        {

        }

        private void label25_Click(object sender, EventArgs e)
        {

        }

        private void label27_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click_1(object sender, EventArgs e)
        {

            string message = "Do you want to confirm this data?";
            string title = "Close Window";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                this.Close();
            }
            else
            {
                // Do something  
            }

        }

        private void button11_Click(object sender, EventArgs e)
        {





            {
            }
        }

        private void button11_Click_1(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {


            string ConnectionString = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            SqlConnection con = new SqlConnection(ConnectionString);
            con.Open();
            string query = "DELETE FROM Tb4_Employee where Staffid = '" + textBox1.Text + "';";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();
            MessageBox.Show("Record deleted successfully.");
            con.Close();
            populate();
        }






        private void button11_Click_2(object sender, EventArgs e)
        {

            {
                MyForm form = new MyForm();
                form.Show(); // or form.ShowDialog(this);
            }
        }

        private void button11_Click_3(object sender, EventArgs e)
        {

        }

        private void label24_Click(object sender, EventArgs e)
        {

        }

        private void textBox20_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void label24_Click_1(object sender, EventArgs e)
        {

            {
                DialogResult d;
                d = MessageBox.Show("Do you want to log out?", "Log out", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
                if (d == DialogResult.Yes)
                {
                    Close();
                }
            }
            System.Windows.Forms.Application.Exit();
        }

        private void tabPage3_Click(object sender, EventArgs e)
        {

        }

       

        internal class login
        {
            public login()
            {
            }

            internal void Show()
            {
                throw new NotImplementedException();
            }
        }

        

        private void button6_Click_1(object sender, EventArgs e)
        {

            string message = "Do you want to confirm this data?";
            string title = "Close Window";
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;
            DialogResult result = MessageBox.Show(message, title, buttons);
            if (result == DialogResult.Yes)
            {
                this.Close();
            }
            else
            {
                // Do something  
            }

        
    }

        private void button8_Click_2(object sender, EventArgs e)
        {
            Form1 Check = new Form1();
            Check.Show();
        }

        private void tabPage7_Click(object sender, EventArgs e)
        {

        }

        

        private void dataGridView3_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                string MyConnection2 = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
                //Display query  
                string Query = "select * from Tb4_Employee;";
                SqlConnection MyConn2 = new SqlConnection(MyConnection2);
                SqlCommand MyCommand2 = new SqlCommand(Query, MyConn2);
                //  MyConn2.Open();  
                //For offline connection we weill use  MySqlDataAdapter class.  
                SqlDataAdapter MyAdapter = new SqlDataAdapter();
                MyAdapter.SelectCommand = MyCommand2;
                DataTable dTable = new DataTable();
                MyAdapter.Fill(dTable);
                dataGridView1.DataSource = dTable; // here i have assign dTable object to the dataGridView1 object to display data.               
                                                   // MyConn2.Close();  
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }





        }

        private void pictureBox4_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
           





        

    }

        private void tabPage4_Click_1(object sender, EventArgs e)
        {

        }

        private void button8_Click_3(object sender, EventArgs e)
        {

            {
                DialogResult d;
                d = MessageBox.Show("Do you want to log out?", "Log out", MessageBoxButtons.YesNo, MessageBoxIcon.Information);
                if (d == DialogResult.Yes)
                {
                    Close();
                }
            }
            System.Windows.Forms.Application.Exit();
        
    }

        private void button5_Click(object sender, EventArgs e)
        {
            string ConnectionString = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            SqlConnection con = new SqlConnection(ConnectionString);
            con.Open();
            string query = "TRUNCATE TABLE Tb4_Employee;";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {

        }

        private void button9_Click_1(object sender, EventArgs e)
        {
            Form1 Check = new Form1();
            Check.Show();

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {

            DateTime t;
            t = dateTimePicker1.Value;
            //MessageBox.Show(t.ToString());
            try
            {
                String aa = "";
                if (radioButton1.Checked == true) { aa = "male"; } else { aa = "female"; }
                String str = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";

                String query = "select * from staff_tb1";

                SqlConnection con = new SqlConnection(str);

                SqlCommand cmd = new SqlCommand(query, con);

                con.Open();

                DataSet ds = new DataSet();

                // textBox1.Text = "hello";
                //MessageBox.Show("aa");
                //textBox2.Text = textBox1.Text;
                string a = textBox1.Text;


                con.Close();

                string qury = "INSERT INTO Tb4_Employee VALUES(@a,@b,@c,@d,@name,@e,@f,@g,@h,@ei,@ej,@ek,@el,@em,@ee,@ew,@et,@ey,@eu,@eee)";

                cmd = new SqlCommand(qury, con);
                cmd.Parameters.AddWithValue("@a", comboBox1.Text);
                cmd.Parameters.AddWithValue("@b", textBox1.Text);
                cmd.Parameters.AddWithValue("@c", aa);
                cmd.Parameters.AddWithValue("@name", "NULL");

                cmd.Parameters.AddWithValue("@d", textBox2.Text);
                cmd.Parameters.AddWithValue("@e", textBox3.Text);
                cmd.Parameters.AddWithValue("@f", textBox4.Text);
                cmd.Parameters.AddWithValue("@h", t.ToString());
                cmd.Parameters.AddWithValue("@g", textBox5.Text);
                cmd.Parameters.AddWithValue("@ei", textBox6.Text);
                cmd.Parameters.AddWithValue("@ej", textBox7.Text);
                cmd.Parameters.AddWithValue("@ek", textBox8.Text);
                cmd.Parameters.AddWithValue("@el", textBox9.Text);
                cmd.Parameters.AddWithValue("@eee", comboBox2.Text);
                cmd.Parameters.AddWithValue("@em", textBox10.Text);
                cmd.Parameters.AddWithValue("@en", textBox11.Text);
                cmd.Parameters.AddWithValue("@ew", textBox12.Text);
                cmd.Parameters.AddWithValue("@ee", textBox13.Text);
                cmd.Parameters.AddWithValue("@et", textBox14.Text);
                cmd.Parameters.AddWithValue("@ey", textBox15.Text);
                cmd.Parameters.AddWithValue("@eu", textBox16.Text);


                con.Open();
                cmd.ExecuteNonQuery();
                con.Close();

                MessageBox.Show(" DATA SuccessFully INSERTED!");









            }
            catch (Exception es)
            {


                MessageBox.Show(es.Message);







            }

        
    }

        private void button4_Click_1(object sender, EventArgs e)
        {
            string ConnectionString = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            SqlConnection con = new SqlConnection(ConnectionString);
            con.Open();
            string query = "TRUNCATE TABLE Tb4_Employee;";
            SqlCommand cmd = new SqlCommand(query, con);
            cmd.ExecuteNonQuery();
        }

        private void button11_Click_4(object sender, EventArgs e)
        {
            string MyConnection2 = "server=DESKTOP-J2LUKJS\\SQLEXPRESS;database=emp;Integrated Security=true;";
            //Display query  
            string Query = "select * from Tb4_Employee;";
            SqlConnection MyConn2 = new SqlConnection(MyConnection2);
            SqlCommand MyCommand2 = new SqlCommand(Query, MyConn2);
            //  MyConn2.Open();  
            //For offline connection we weill use  MySqlDataAdapter class.  
            SqlDataAdapter MyAdapter = new SqlDataAdapter();
            MyAdapter.SelectCommand = MyCommand2;
            DataTable dTable = new DataTable();
            MyAdapter.Fill(dTable);
            dataGridView1.DataSource = dTable;


        }
    }
}






