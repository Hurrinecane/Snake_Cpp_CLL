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
		Snake^ snake = gcnew Snake();
		int direction = RIGHT;

		Image^ whallImg;
		Image^ backWhallImg;
		Image^ appleImg;
		Image^ bodyImg;
		Image^ headImg;

		int mapSize = 15;
		int offset = 12;
		int** mapMas = new  int* [mapSize];
		int blockSize;

		double time = 0;
		int appletime = 0;

		bool apple = false;
		bool Running = false;
		bool lose = false;


	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Button^ PauseButton;
	private: System::Windows::Forms::Button^ RightButton;
	private: System::Windows::Forms::Button^ UpButoon;
	private: System::Windows::Forms::Button^ DownButtom;
	private: System::Windows::Forms::Button^ LeftButton;
	private: System::Windows::Forms::Label^ SnakeSizeLabel;
	private: System::Windows::Forms::Label^ TimeLabel;
	private: System::Windows::Forms::Label^ InfoLabel;

	private: System::Windows::Forms::Button^ StartButton;

	public:
		Snake_Game(void)
		{
			InitializeComponent();
			this->DoubleBuffered = true;

			whallImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\whall.bmp");
			backWhallImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\grass.bmp");
			appleImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\apple.bmp");
			bodyImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\Body.bmp");
			headImg = Bitmap::FromFile(Application::StartupPath + "\\Textures\\Head.bmp");

			blockSize = Width * 0.73 / mapSize;

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

			snake->CreateSnake(mapSize);
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
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->InfoLabel = (gcnew System::Windows::Forms::Label());
			   this->TimeLabel = (gcnew System::Windows::Forms::Label());
			   this->SnakeSizeLabel = (gcnew System::Windows::Forms::Label());
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
			   // panel1
			   // 
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->panel1->CausesValidation = false;
			   this->panel1->Controls->Add(this->InfoLabel);
			   this->panel1->Controls->Add(this->TimeLabel);
			   this->panel1->Controls->Add(this->SnakeSizeLabel);
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
			   // label1
			   // 
			   this->InfoLabel->AutoSize = true;
			   this->InfoLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->InfoLabel->Location = System::Drawing::Point(37, 235);
			   this->InfoLabel->Name = L"label1";
			   this->InfoLabel->Size = System::Drawing::Size(72, 91);
			   this->InfoLabel->TabIndex = 8;
			   this->InfoLabel->Text = L"\r\nУправление:\r\nW - Вверх;\r\nS - Вниз;\r\nA - Влево;\r\nD - Вправо;\r\nP - Пауза; ";
			   // 
			   // TimeLabel
			   // 
			   this->TimeLabel->AutoSize = true;
			   this->TimeLabel->Location = System::Drawing::Point(4, 70);
			   this->TimeLabel->Name = L"TimeLabel";
			   this->TimeLabel->Size = System::Drawing::Size(49, 13);
			   this->TimeLabel->TabIndex = 7;
			   this->TimeLabel->Text = L"Время:  ";
			   this->TimeLabel->Visible = false;
			   // 
			   // SnakeSizeLabel
			   // 
			   this->SnakeSizeLabel->AutoSize = true;
			   this->SnakeSizeLabel->Location = System::Drawing::Point(4, 53);
			   this->SnakeSizeLabel->Name = L"SnakeSizeLabel";
			   this->SnakeSizeLabel->Size = System::Drawing::Size(84, 13);
			   this->SnakeSizeLabel->TabIndex = 6;
			   this->SnakeSizeLabel->Text = L"Длина змейки:";
			   this->SnakeSizeLabel->Visible = false;
			   // 
			   // StartButton
			   // 
			   this->StartButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->StartButton->Location = System::Drawing::Point(3, 3);
			   this->StartButton->Name = L"StartButton";
			   this->StartButton->Size = System::Drawing::Size(141, 43);
			   this->StartButton->TabIndex = 5;
			   this->StartButton->Text = L"Start";
			   this->StartButton->UseVisualStyleBackColor = true;
			   this->StartButton->Click += gcnew System::EventHandler(this, &Snake_Game::StartButton_Click);
			   this->StartButton->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // PauseButton
			   // 
			   this->PauseButton->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->PauseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(204)));
			   this->PauseButton->Location = System::Drawing::Point(52, 401);
			   this->PauseButton->Name = L"PauseButton";
			   this->PauseButton->Size = System::Drawing::Size(43, 43);
			   this->PauseButton->TabIndex = 4;
			   this->PauseButton->Text = L"⏯";
			   this->PauseButton->UseVisualStyleBackColor = true;
			   this->PauseButton->Click += gcnew System::EventHandler(this, &Snake_Game::PauseButton_Click);
			   this->PauseButton->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // RightButton
			   // 
			   this->RightButton->Cursor = System::Windows::Forms::Cursors::PanEast;
			   this->RightButton->Location = System::Drawing::Point(101, 401);
			   this->RightButton->Name = L"RightButton";
			   this->RightButton->Size = System::Drawing::Size(43, 43);
			   this->RightButton->TabIndex = 3;
			   this->RightButton->Text = L"Right";
			   this->RightButton->UseVisualStyleBackColor = true;
			   this->RightButton->Click += gcnew System::EventHandler(this, &Snake_Game::RightButton_Click);
			   this->RightButton->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // UpButoon
			   // 
			   this->UpButoon->Cursor = System::Windows::Forms::Cursors::PanNorth;
			   this->UpButoon->Location = System::Drawing::Point(52, 352);
			   this->UpButoon->Name = L"UpButoon";
			   this->UpButoon->Size = System::Drawing::Size(43, 43);
			   this->UpButoon->TabIndex = 2;
			   this->UpButoon->Text = L"Up";
			   this->UpButoon->UseVisualStyleBackColor = true;
			   this->UpButoon->Click += gcnew System::EventHandler(this, &Snake_Game::UpButoon_Click);
			   this->UpButoon->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // DownButtom
			   // 
			   this->DownButtom->Cursor = System::Windows::Forms::Cursors::PanSouth;
			   this->DownButtom->Location = System::Drawing::Point(52, 450);
			   this->DownButtom->Name = L"DownButtom";
			   this->DownButtom->Size = System::Drawing::Size(43, 43);
			   this->DownButtom->TabIndex = 1;
			   this->DownButtom->Text = L"Down";
			   this->DownButtom->UseMnemonic = false;
			   this->DownButtom->UseVisualStyleBackColor = true;
			   this->DownButtom->Click += gcnew System::EventHandler(this, &Snake_Game::DownButtom_Click);
			   this->DownButtom->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // LeftButton
			   // 
			   this->LeftButton->Cursor = System::Windows::Forms::Cursors::PanWest;
			   this->LeftButton->Location = System::Drawing::Point(3, 401);
			   this->LeftButton->Name = L"LeftButton";
			   this->LeftButton->Size = System::Drawing::Size(43, 43);
			   this->LeftButton->TabIndex = 0;
			   this->LeftButton->Text = L"Left";
			   this->LeftButton->UseVisualStyleBackColor = true;
			   this->LeftButton->Click += gcnew System::EventHandler(this, &Snake_Game::LeftButton_Click);
			   this->LeftButton->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   // 
			   // Snake_Game
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(679, 524);
			   this->Controls->Add(this->panel1);
			   this->DoubleBuffered = true;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			   this->MaximizeBox = false;
			   this->Name = L"Snake_Game";
			   this->ShowIcon = false;
			   this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			   this->Text = L"Snake";
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Snake_Game::mapField_Paint);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Snake_Game::Snake_Game_KeyDown);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

#pragma region Logic

	private:   System::Void Annul()
	{
		appletime = 0;

		snake->DelSnake();

		SnakeSizeLabel->Text = L"Длина змейки: ";
		TimeLabel->Text = L"Время: ";
		time = 0;

		direction = 1;
		Running = false;
		timer1->Stop();
		SnakeSizeLabel->Visible = false;
		TimeLabel->Visible = false;
		InfoLabel->Visible = true;
		StartButton->Text = "Start";
	}

	private:   System::Void Collision()
	{
		if (mapMas[snake->head->y][snake->head->x] == 1)
		{
			Annul();
			snake->CreateSnake(mapSize);
			return;
		}
		for (Node* cur = snake->head->prev; cur != nullptr; cur = cur->prev)
		{
			if (snake->head->x == cur->x && snake->head->y == cur->y)
			{
				snake->Cut(cur->next);
				break;
			}
		}

		if (mapMas[snake->head->y][snake->head->x] == 2)
		{
			mapMas[snake->head->y][snake->head->x] = 0;
			snake->Growing();
			apple = false;
		}
	}

	private:   System::Void Apple()
	{
		int x, y;
		do
		{
			bool check = true;
			x = rand() % (mapSize - 1) + 1;
			y = rand() % (mapSize - 1) + 1;
			for (Node* tmp = snake->head; tmp != nullptr; tmp = tmp->next)
				if (x == tmp->x || y == tmp->y || mapMas[y][x] != 0)
					check = false;

			if (check) mapMas[y][x] = 2;
		} while (mapMas[y][x] != 2);
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		Invalidate();
		snake->Crawl(direction);

		Collision();
		if (!timer1->Enabled)
			return;
		time = time + double(timer1->Interval) / 1000;
		SnakeSizeLabel->Text = L"Длина змейки: " + snake->SnakeSize;
		TimeLabel->Text = L"Время: " + time;

		if (!apple) appletime = appletime++;

		if (appletime > 5 && apple == false)
		{
			Apple();
			appletime = 0;
			apple = true;
		}

		//...
	}
#pragma endregion

#pragma region drawing

	private: System::Void DrawMap(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		for (int i = 0; i < mapSize; i++)
			for (int j = 0; j < mapSize; j++)
			{
				switch (mapMas[j][i])
				{
				case 0:
					e->Graphics->DrawImage(backWhallImg, offset + i * blockSize, offset + j * blockSize, blockSize, blockSize);
					break;
				case 1:
					e->Graphics->DrawImage(whallImg, offset + i * blockSize, offset + j * blockSize, blockSize, blockSize);
					break;
				case 2:
					e->Graphics->DrawImage(appleImg, offset + i * blockSize, offset + j * blockSize, blockSize, blockSize);
					break;
				case 3:

					break;
				}
			}
	}

	private: System::Void DrawSnake(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		for (Node* tmp = snake->tail; tmp != snake->head; tmp = tmp->next)
		{
			e->Graphics->DrawImage(bodyImg, offset + tmp->x * blockSize, offset + tmp->y * blockSize, blockSize, blockSize);
		}
		e->Graphics->DrawImage(headImg, offset + snake->head->x * blockSize, offset + snake->head->y * blockSize, blockSize, blockSize);

	}
	private: System::Void mapField_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		DrawMap(sender, e);
		DrawSnake(sender, e);
	}
#pragma endregion

#pragma region Control

	private: System::Void Snake_Game_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		switch (e->KeyCode) {
		case Keys::D:
			if (direction != LEFT)
				direction = RIGHT;
			break;
		case Keys::A:
			if (direction != RIGHT)
				direction = LEFT;
			break;
		case Keys::W:
			if (direction != DOWN)
				direction = UP;
			break;
		case Keys::S:
			if (direction != UP)
				direction = DOWN;
			break;
		case Keys::P:
			if (timer1->Enabled)
				timer1->Stop();
			else
				timer1->Start();
			break;
		}
	}

	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (Running)
		{
			Annul();
			Invalidate();
			snake->CreateSnake(mapSize);
		}
		else
		{
			Running = true;
			SnakeSizeLabel->Visible = true;
			TimeLabel->Visible = true;
			InfoLabel->Visible = false;
			timer1->Start();
			timer1->Interval = 500;
			StartButton->Text = "Restart";
		}
	}
	private: System::Void UpButoon_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (direction != DOWN)
			direction = UP;
	}
	private: System::Void DownButtom_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (direction != UP)
			direction = DOWN;
	}
	private: System::Void RightButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (direction != LEFT)
			direction = RIGHT;
	}
	private: System::Void LeftButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (direction != RIGHT)
			direction = LEFT;
	}
	private: System::Void PauseButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (timer1->Enabled)
			timer1->Stop();
		else
			timer1->Start();
	}
#pragma endregion
	};
}