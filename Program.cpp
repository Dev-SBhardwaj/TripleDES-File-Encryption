//.h file code:

namespace TripleDES_Enc
{
	class Program final
	{
		/// The main entry point for the application.
	public:

//[STAThread] static void Main()
		static void Main();
};
}




int main(int argc, char** argv)
{
	TripleDES_Enc::Program::Main();
}

//.cpp file code:

# include "snippet.h"

namespace TripleDES_Enc
{

	void Program::Main()
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Form1 tempVar();
		Application::Run(&tempVar);
	}
}
