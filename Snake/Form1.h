#pragma once
#include "Snake.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Snake_Game : public System::Windows::Forms::Form
	{
	private:
		Image^ whallImg;
		Image^ backWhallImg;
		Image^ appleImg;

		int mapSize = 10;
		int** mapMas = new  int* [mapSize];
		int blockSize;

	private: System::Windows::Forms::Panel^ mapField;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ PauseButton;
	private: System::Windows::Forms::Button^ RightButton;
	private: System::Windows::Forms::Button^ UpButoon;
	private: System::Windows::Forms::Button^ DownButtom;
	private: System::Windows::Forms::Button^ LeftButton;

	private: System::Windows::Forms::Button^ StartButton;

	public:
		Snake_Game(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;

			whallImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\whall.bmp");
			backWhallImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\grass.bmp");
			appleImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\apple.bmp");

			Snake snake(mapSize, blockSize);

			for (int i = 0; i < mapSize; i++)
				mapMas[i] = new int[mapSize];

			//заполнение карты
			for (int j = 0; j < mapSize; j++)
				mapMas[0][j] = mapMas[mapSize - 1][j] = 1;
			for (int i = 1; i < mapSize - 1; i++)
			{
				mapMas[i][0] = mapMas[i][mapSize - 1] = 1;
				for (int j = 1; j < mapSize - 1; j++)
					mapMas[i][j] = 0;
			}
			//***
			blockSize = mapField->Width / mapSize;
		}

	protected:

		~Snake_Game()
		{
			for (int i = 0; i < mapSize; i++)
				delete[] mapMas[i];

			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private: System::Windows::Forms::Timer^ timer1;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->mapField = (gcnew System::Windows::Forms::Panel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->StartButton = (gcnew System::Windows::Forms::Button());
			   this->PauseButton = (gcnew System::Windows::Forms::Button());
			   this->RightButton = (gcnew System::Windows::Forms::Button());
			   this->UpButoon = (gcnew System::Windows::Forms::Button());
			   this->DownButtom = (gcnew System::Windows::Forms::Button());
			   this->LeftButton = (gcnew System::Windows::Forms::Button());
			   this->panel1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Tick += gcnew System::EventHandler(this, &Snake_Game::timer1_Tick);
			   // 
			   // mapField
			   // 
			   this->mapField->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->mapField->Location = System::Drawing::Point(12, 12);
			   this->mapField->Name = L"mapField";
			   this->mapField->Size = System::Drawing::Size(500, 500);
			   this->mapField->TabIndex = 0;
			   this->mapField->Visible = false;
			   // 
			   // panel1
			   // 
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->Controls->Add(this->StartButton);
			   this->panel1->Controls->Add(this->PauseButton);
			   this->panel1->Controls->Add(this->RightButton);
			   this->panel1->Controls->Add(this->UpButoon);
			   this->panel1->Controls->Add(this->DownButtom);
			   this->panel1->Controls->Add(this->LeftButton);
			   this->panel1->Location = System::Drawing::Point(518, 12);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(151, 500);
			   this->panel1->TabIndex = 1;
			   // 
			   // StartButton
			   // 
			   this->StartButton->Location = System::Drawing::Point(3, 3);
			   this->StartButton->Name = L"StartButton";
			   this->StartButton->Size = System::Drawing::Size(141, 43);
			   this->StartButton->TabIndex = 5;
			   this->StartButton->Text = L"Start";
			   this->StartButton->UseVisualStyleBackColor = true;
			   this->StartButton->Click += gcnew System::EventHandler(this, &Snake_Game::StartButton_Click);
			   // 
			   // PauseButton
			   // 
			   this->PauseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->PauseButton->Location = System::Drawing::Point(52, 401);
			   this->PauseButton->Name = L"PauseButton";
			   this->PauseButton->Size = System::Drawing::Size(43, 43);
			   this->PauseButton->TabIndex = 4;
			   this->PauseButton->Text = L"⏯";
			   this->PauseButton->UseVisualStyleBackColor = true;
			   this->PauseButton->Click += gcnew System::EventHandler(this, &Snake_Game::PauseButton_Click);
			   // 
			   // RightButton
			   // 
			   this->RightButton->Location = System::Drawing::Point(101, 401);
			   this->RightButton->Name = L"RightButton";
			   this->RightButton->Size = System::Drawing::Size(43, 43);
			   this->RightButton->TabIndex = 3;
			   this->RightButton->Text = L"Right";
			   this->RightButton->UseVisualStyleBackColor = true;
			   // 
			   // UpButoon
			   // 
			   this->UpButoon->Location = System::Drawing::Point(52, 352);
			   this->UpButoon->Name = L"UpButoon";
			   this->UpButoon->Size = System::Drawing::Size(43, 43);
			   this->UpButoon->TabIndex = 2;
			   this->UpButoon->Text = L"Up";
			   this->UpButoon->UseVisualStyleBackColor = true;
			   // 
			   // DownButtom
			   // 
			   this->DownButtom->Location = System::Drawing::Point(52, 450);
			   this->DownButtom->Name = L"DownButtom";
			   this->DownButtom->Size = System::Drawing::Size(43, 43);
			   this->DownButtom->TabIndex = 1;
			   this->DownButtom->Text = L"Down";
			   this->DownButtom->UseMnemonic = false;
			   this->DownButtom->UseVisualStyleBackColor = true;
			   // 
			   // LeftButton
			   // 
			   this->LeftButton->Location = System::Drawing::Point(3, 401);
			   this->LeftButton->Name = L"LeftButton";
			   this->LeftButton->Size = System::Drawing::Size(43, 43);
			   this->LeftButton->TabIndex = 0;
			   this->LeftButton->Text = L"Left";
			   this->LeftButton->UseVisualStyleBackColor = true;
			   // 
			   // Snake_Game
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(679, 524);
			   this->Controls->Add(this->panel1);
			   this->Controls->Add(this->mapField);
			   this->DoubleBuffered = true;
			   this->MaximizeBox = false;
			   this->Name = L"Snake_Game";
			   this->ShowIcon = false;
			   this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			   this->Text = L"Snake";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Snake_Game::Form1_Paint);
			   this->panel1->ResumeLayout(false);
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		this->Invalidate();
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (timer1->Enabled)
		{
			timer1->Stop();
			StartButton->Text = "Start";
			//...
		}
		else
		{
			timer1->Start();
			StartButton->Text = "Restart";
		}

	}
	private: System::Void PauseButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (timer1->Enabled)
			timer1->Stop();
		else
			timer1->Start();
	}

	private: System::Void DrawMap(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		   {
			   for (int i = 0; i < mapSize; i++)
				   for (int j = 0; j < mapSize; j++)
				   {
					   if (mapMas[i][j] == 0)
					   {
						   e->Graphics->DrawImage(backWhallImg, mapField->Location.X + i * blockSize, mapField->Location.Y + j * blockSize, blockSize, blockSize);
					   }
					   if (mapMas[i][j] == 1)
					   {
						   e->Graphics->DrawImage(whallImg, mapField->Location.X + i * blockSize, mapField->Location.Y + j * blockSize, blockSize, blockSize);
					   }
					   if (mapMas[i][j] == 2)
					   {
						   e->Graphics->DrawImage(appleImg, mapField->Location.X + i * blockSize, mapField->Location.Y + j * blockSize, blockSize, blockSize);
					   }
				   }
		   }
	private: System::Void Form1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		//отрисовка карты
		DrawMap(sender, e);

	}
	};
}
