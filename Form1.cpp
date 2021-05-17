//.h file code:

# include <stdexcept>
# include <any>

namespace TripleDES_Enc
{
	class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1();

	private:
		void button1_Click(std::any sender, EventArgs* e);

	void button2_Click(std::any sender, EventArgs* e);

	void button3_Click(std::any sender, EventArgs* e);
};
}

//.cpp file code:

#include "snippet.h"

namespace TripleDES_Enc
{

	Form1::Form1()
	{
		InitializeComponent();
}

void Form1::button1_Click(std::any sender, EventArgs* e)
{
	OpenFileDialog* OD = new OpenFileDialog();
	OD->Filter = L"All Files|*";
	OD->FileName = L"";
	if (OD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		textBox1->Text = OD->FileName;
	}

	delete OD;
}

void Form1::button2_Click(std::any sender, EventArgs* e)
{
	try
	{
		TripleDES* tDES = new TripleDES(textBox2->Text);
		tDES->EncryptFile(textBox1->Text);
		GC::Collect();

		delete tDES;
	}
	catch (const std::runtime_error &ex)
		{
		MessageBox::Show(ex.what());
	}
	}

	void Form1::button3_Click(std::any sender, EventArgs * e)
	{
		try
		{
			TripleDES* tDES = new TripleDES(textBox2->Text);
			tDES->DecryptFile(textBox1->Text);
			GC::Collect();

			delete tDES;
		}
		catch (const std::runtime_error &ex)
		{
			MessageBox::Show(ex.what());
		}
		}
	}
