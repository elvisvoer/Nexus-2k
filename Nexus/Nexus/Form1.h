#pragma once

#include "Drawer.h"
#include "Game.h"

Game g;
bool select = false;

namespace Nexus2k {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::Label^  score;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->score = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->pictureBox1->Location = System::Drawing::Point(14, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(360, 360);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// start
			// 
			this->start->Location = System::Drawing::Point(463, 53);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(87, 25);
			this->start->TabIndex = 1;
			this->start->Text = L"Start!";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Form1::start_Click);
			// 
			// score
			// 
			this->score->AutoSize = true;
			this->score->Font = (gcnew System::Drawing::Font(L"Niagara Engraved", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->score->Location = System::Drawing::Point(15, 14);
			this->score->Name = L"score";
			this->score->Size = System::Drawing::Size(45, 23);
			this->score->TabIndex = 2;
			this->score->Text = L"00000";
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 496);
			this->Controls->Add(this->score);
			this->Controls->Add(this->start);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(!g.isGameStarted())
				 {
					 Drawer::init(pictureBox1->CreateGraphics());
					 g.start();
					 g.draw();
					 timer1->Start();
				 }
				 else
				 {
					 g.nextMove();
					 pictureBox1->Invalidate();
				 }
			 }
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
				if(!g.isGameStarted())
					return;

				int x = ((MouseEventArgs^)e)->X / BLOCK_SIZE;
				int y = ((MouseEventArgs^)e)->Y / BLOCK_SIZE;
				g.selectOrMove(y, x);
				select = true;
				pictureBox1->Invalidate();
				 
			 }
	private: System::Void pictureBox1_Paint(Object^ sender, PaintEventArgs^ e) {
				Drawer::init(e->Graphics);
				g.draw(select);
				String^ formatted = String::Format("{0,8:00000000}", g.getScore());
				score->Text = formatted;
				select = !select;
			}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {	
				 pictureBox1->Invalidate();	
			 }
};
}

