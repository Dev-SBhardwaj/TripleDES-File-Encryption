//.h file code:

# include <string>
# include <vector>

namespace TripleDES_Enc
{
	class TripleDES
	{
		private:
		TripleDESCryptoServiceProvider* des = new TripleDESCryptoServiceProvider();
		public:
		virtual ~TripleDES()
		{
			delete des;
		}

		TripleDES(const std::wstring &key);

		void EncryptFile(const std::wstring &filepath);

		void DecryptFile(const std::wstring &filepath);
	};
}

//.cpp file code:

# include "snippet.h"

namespace TripleDES_Enc
{

	TripleDES::TripleDES(const std::wstring &key)
	{
		des->Key = UTF8Encoding::UTF8->GetBytes(key);
	des->Mode = CipherMode::ECB; //Electronic Code Book
		des->Padding = PaddingMode::PKCS7;
	}

void TripleDES::EncryptFile(const std::wstring &filepath)
{
	std::vector < unsigned char> Bytes = File::ReadAllBytes(filepath);
	std::vector < unsigned char> eBytes = des->CreateEncryptor()->TransformFinalBlock(Bytes, 0, Bytes.size());
	File::WriteAllBytes(filepath, eBytes);
}

void TripleDES::DecryptFile(const std::wstring &filepath)
{
	std::vector < unsigned char> Bytes = File::ReadAllBytes(filepath);
	std::vector < unsigned char> dBytes = des->CreateDecryptor()->TransformFinalBlock(Bytes, 0, Bytes.size());
	File::WriteAllBytes(filepath, dBytes);
}
}
