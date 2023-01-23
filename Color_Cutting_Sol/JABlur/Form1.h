#ifndef FORM1_H
#define FORM1_H

//#include "BMP.h"
#include "ImageF.h"

typedef void(__cdecl* MYPROC)(BYTE*, BYTE*, BYTE*); //definicja typu wskaznika

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

namespace CppCLRWinFormsProject {
	/// <summary>
	/// Summary for Form1
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

			// uncomment to execute the rk1-utils:
			//    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used
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
	private: System::Windows::Forms::Button^ startButton;
	private: System::Windows::Forms::Button^ loadButton;

	private: System::Windows::Forms::RadioButton^ radioCppMode;
	private: System::Windows::Forms::RadioButton^ radioAsmMode;
	protected:

	private: System::Windows::Forms::BindingSource^ bindingSource1;
	private: System::Windows::Forms::TrackBar^ threadCountTrackBar;

	private: System::Windows::Forms::TextBox^ threadCountTextBox;
	private: System::Windows::Forms::TextBox^ threadNumberTextBox;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textTime;
	private: System::Windows::Forms::TextBox^ ShowTime;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ InputPic;
	private: System::Windows::Forms::PictureBox^ OutputPic;
	private: System::Windows::Forms::NumericUpDown^ seekRED;
	private: System::Windows::Forms::NumericUpDown^ seekGREEN;
	private: System::Windows::Forms::NumericUpDown^ seekBLUE;
	private: System::Windows::Forms::NumericUpDown^ changeRED;
	private: System::Windows::Forms::NumericUpDown^ changeGREEN;
	private: System::Windows::Forms::NumericUpDown^ changeBLUE;





	private: System::Windows::Forms::Label^ R;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;






	private: System::ComponentModel::IContainer^ components;
	protected:

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
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->radioCppMode = (gcnew System::Windows::Forms::RadioButton());
			this->radioAsmMode = (gcnew System::Windows::Forms::RadioButton());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->threadCountTrackBar = (gcnew System::Windows::Forms::TrackBar());
			this->threadCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->threadNumberTextBox = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textTime = (gcnew System::Windows::Forms::TextBox());
			this->ShowTime = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->InputPic = (gcnew System::Windows::Forms::PictureBox());
			this->OutputPic = (gcnew System::Windows::Forms::PictureBox());
			this->seekRED = (gcnew System::Windows::Forms::NumericUpDown());
			this->seekGREEN = (gcnew System::Windows::Forms::NumericUpDown());
			this->seekBLUE = (gcnew System::Windows::Forms::NumericUpDown());
			this->changeRED = (gcnew System::Windows::Forms::NumericUpDown());
			this->changeGREEN = (gcnew System::Windows::Forms::NumericUpDown());
			this->changeBLUE = (gcnew System::Windows::Forms::NumericUpDown());
			this->R = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadCountTrackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutputPic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekRED))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekGREEN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekBLUE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeRED))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeGREEN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeBLUE))->BeginInit();
			this->SuspendLayout();
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(268, 382);
			this->startButton->Margin = System::Windows::Forms::Padding(2);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(97, 23);
			this->startButton->TabIndex = 0;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// loadButton
			// 
			this->loadButton->Location = System::Drawing::Point(268, 355);
			this->loadButton->Margin = System::Windows::Forms::Padding(2);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(97, 23);
			this->loadButton->TabIndex = 1;
			this->loadButton->Text = L"Wczytaj zdjêcie";
			this->loadButton->UseVisualStyleBackColor = true;
			this->loadButton->Click += gcnew System::EventHandler(this, &Form1::loadButton_Click);
			// 
			// radioCppMode
			// 
			this->radioCppMode->AutoSize = true;
			this->radioCppMode->Checked = true;
			this->radioCppMode->Location = System::Drawing::Point(86, 307);
			this->radioCppMode->Margin = System::Windows::Forms::Padding(2);
			this->radioCppMode->Name = L"radioCppMode";
			this->radioCppMode->Size = System::Drawing::Size(69, 17);
			this->radioCppMode->TabIndex = 2;
			this->radioCppMode->TabStop = true;
			this->radioCppMode->Text = L"CPP DLL";
			this->radioCppMode->UseVisualStyleBackColor = true;
			this->radioCppMode->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_CppDLL);
			// 
			// radioAsmMode
			// 
			this->radioAsmMode->AutoSize = true;
			this->radioAsmMode->Location = System::Drawing::Point(11, 307);
			this->radioAsmMode->Margin = System::Windows::Forms::Padding(2);
			this->radioAsmMode->Name = L"radioAsmMode";
			this->radioAsmMode->Size = System::Drawing::Size(71, 17);
			this->radioAsmMode->TabIndex = 3;
			this->radioAsmMode->Text = L"ASM DLL";
			this->radioAsmMode->UseVisualStyleBackColor = true;
			this->radioAsmMode->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton_AsmDLL);
			// 
			// threadCountTrackBar
			// 
			this->threadCountTrackBar->Location = System::Drawing::Point(11, 328);
			this->threadCountTrackBar->Margin = System::Windows::Forms::Padding(2);
			this->threadCountTrackBar->Maximum = 64;
			this->threadCountTrackBar->Minimum = 1;
			this->threadCountTrackBar->Name = L"threadCountTrackBar";
			this->threadCountTrackBar->Size = System::Drawing::Size(200, 45);
			this->threadCountTrackBar->TabIndex = 4;
			this->threadCountTrackBar->Value = 1;
			this->threadCountTrackBar->Scroll += gcnew System::EventHandler(this, &Form1::threadCountTrackBar_Scroll);
			// 
			// threadCountTextBox
			// 
			this->threadCountTextBox->BackColor = System::Drawing::SystemColors::Control;
			this->threadCountTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->threadCountTextBox->Location = System::Drawing::Point(11, 377);
			this->threadCountTextBox->Margin = System::Windows::Forms::Padding(2);
			this->threadCountTextBox->Name = L"threadCountTextBox";
			this->threadCountTextBox->Size = System::Drawing::Size(122, 13);
			this->threadCountTextBox->TabIndex = 5;
			this->threadCountTextBox->Text = L"Wybrana liczba w¹tków:";
			this->threadCountTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// threadNumberTextBox
			// 
			this->threadNumberTextBox->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->threadNumberTextBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->threadNumberTextBox->Location = System::Drawing::Point(196, 377);
			this->threadNumberTextBox->Margin = System::Windows::Forms::Padding(2);
			this->threadNumberTextBox->Name = L"threadNumberTextBox";
			this->threadNumberTextBox->Size = System::Drawing::Size(54, 13);
			this->threadNumberTextBox->TabIndex = 6;
			this->threadNumberTextBox->Text = L"1";
			this->threadNumberTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// textTime
			// 
			this->textTime->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textTime->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textTime->Location = System::Drawing::Point(400, 392);
			this->textTime->Margin = System::Windows::Forms::Padding(2);
			this->textTime->Name = L"textTime";
			this->textTime->Size = System::Drawing::Size(82, 13);
			this->textTime->TabIndex = 7;
			this->textTime->Text = L"Czas rozmycia:";
			this->textTime->TextChanged += gcnew System::EventHandler(this, &Form1::TextTime_TextChanged_1);
			// 
			// ShowTime
			// 
			this->ShowTime->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ShowTime->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ShowTime->Location = System::Drawing::Point(486, 392);
			this->ShowTime->Margin = System::Windows::Forms::Padding(2);
			this->ShowTime->Name = L"ShowTime";
			this->ShowTime->Size = System::Drawing::Size(154, 13);
			this->ShowTime->TabIndex = 8;
			this->ShowTime->TextChanged += gcnew System::EventHandler(this, &Form1::ShowTime_TextChanged_2);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(11, 290);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 13);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"Wybór biblioteki:";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(250, 102);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 10;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// InputPic
			// 
			this->InputPic->Location = System::Drawing::Point(12, 13);
			this->InputPic->Name = L"InputPic";
			this->InputPic->Size = System::Drawing::Size(303, 272);
			this->InputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->InputPic->TabIndex = 11;
			this->InputPic->TabStop = false;
			this->InputPic->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
			// 
			// OutputPic
			// 
			this->OutputPic->Location = System::Drawing::Point(321, 13);
			this->OutputPic->Name = L"OutputPic";
			this->OutputPic->Size = System::Drawing::Size(303, 272);
			this->OutputPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->OutputPic->TabIndex = 12;
			this->OutputPic->TabStop = false;
			this->OutputPic->Click += gcnew System::EventHandler(this, &Form1::OutputPic_Click);
			// 
			// seekRED
			// 
			this->seekRED->Location = System::Drawing::Point(486, 288);
			this->seekRED->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->seekRED->Name = L"seekRED";
			this->seekRED->Size = System::Drawing::Size(46, 20);
			this->seekRED->TabIndex = 13;
			this->seekRED->Tag = L"";
			this->seekRED->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 248, 0, 0, 0 });
			// 
			// seekGREEN
			// 
			this->seekGREEN->Location = System::Drawing::Point(486, 314);
			this->seekGREEN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->seekGREEN->Name = L"seekGREEN";
			this->seekGREEN->Size = System::Drawing::Size(46, 20);
			this->seekGREEN->TabIndex = 14;
			this->seekGREEN->Tag = L"";
			this->seekGREEN->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 13, 0, 0, 0 });
			// 
			// seekBLUE
			// 
			this->seekBLUE->Location = System::Drawing::Point(486, 340);
			this->seekBLUE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->seekBLUE->Name = L"seekBLUE";
			this->seekBLUE->Size = System::Drawing::Size(46, 20);
			this->seekBLUE->TabIndex = 15;
			this->seekBLUE->Tag = L"";
			this->seekBLUE->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 79, 0, 0, 0 });
			// 
			// changeRED
			// 
			this->changeRED->Location = System::Drawing::Point(578, 288);
			this->changeRED->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->changeRED->Name = L"changeRED";
			this->changeRED->Size = System::Drawing::Size(46, 20);
			this->changeRED->TabIndex = 16;
			this->changeRED->Tag = L"";
			// 
			// changeGREEN
			// 
			this->changeGREEN->Location = System::Drawing::Point(578, 314);
			this->changeGREEN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->changeGREEN->Name = L"changeGREEN";
			this->changeGREEN->Size = System::Drawing::Size(46, 20);
			this->changeGREEN->TabIndex = 17;
			this->changeGREEN->Tag = L"";
			// 
			// changeBLUE
			// 
			this->changeBLUE->Location = System::Drawing::Point(578, 340);
			this->changeBLUE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 255, 0, 0, 0 });
			this->changeBLUE->Name = L"changeBLUE";
			this->changeBLUE->Size = System::Drawing::Size(46, 20);
			this->changeBLUE->TabIndex = 18;
			this->changeBLUE->Tag = L"";
			// 
			// R
			// 
			this->R->AutoSize = true;
			this->R->Location = System::Drawing::Point(445, 290);
			this->R->Name = L"R";
			this->R->Size = System::Drawing::Size(18, 13);
			this->R->TabIndex = 19;
			this->R->Text = L"R:";
			this->R->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(445, 316);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 13);
			this->label3->TabIndex = 20;
			this->label3->Text = L"G:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(445, 342);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"B:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(460, 365);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 13);
			this->label2->TabIndex = 22;
			this->label2->Text = L"KolorSzukany";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click_1);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(538, 365);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"KolorZastêpuj¹cy";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(636, 416);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->R);
			this->Controls->Add(this->changeBLUE);
			this->Controls->Add(this->changeGREEN);
			this->Controls->Add(this->changeRED);
			this->Controls->Add(this->seekBLUE);
			this->Controls->Add(this->seekGREEN);
			this->Controls->Add(this->seekRED);
			this->Controls->Add(this->OutputPic);
			this->Controls->Add(this->InputPic);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->ShowTime);
			this->Controls->Add(this->textTime);
			this->Controls->Add(this->threadNumberTextBox);
			this->Controls->Add(this->threadCountTextBox);
			this->Controls->Add(this->threadCountTrackBar);
			this->Controls->Add(this->radioAsmMode);
			this->Controls->Add(this->radioCppMode);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->startButton);
			this->Name = L"Form1";
			this->Text = L"Wycinanie koloru";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadCountTrackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InputPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OutputPic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekRED))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekGREEN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->seekBLUE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeRED))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeGREEN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->changeBLUE))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// You can call the functions at a button click. If you prefer,
		 // you can call them by clicking a menu item.

	private: System::Void radioButton_CppDLL(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton_AsmDLL(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void threadCountTrackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
		threadNumberTextBox->Text = threadCountTrackBar->Value.ToString();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (label1->Text == "")
		{
			throw gcnew System::Exception("Musisz wybraæ zdjêcie");
		}

		bool isCppDllChecked;
		if (this->radioCppMode->Checked == true)
			isCppDllChecked = true;
		else
			isCppDllChecked = false;

		std::string ifilename;
		MarshalString(openFileDialog1->FileName->ToString(), ifilename);
		const char* c = ifilename.c_str();

		byte kolory[6] = {seekBLUE->Value.ToByte(seekBLUE->Value),seekBLUE->Value.ToByte(seekGREEN->Value),seekBLUE->Value.ToByte(seekRED->Value),seekBLUE->Value.ToByte(changeBLUE->Value),seekBLUE->Value.ToByte(changeGREEN->Value),seekBLUE->Value.ToByte(changeRED->Value) };

		int time = run(c, "gotowe_zdjecie.bmp", threadCountTrackBar->Value, isCppDllChecked, kolory);
		System::String^ text = gcnew System::String(time + " " + "mikrosekund");
		this->ShowTime->Text = text;
		OutputPic->Load("gotowe_zdjecie.bmp");
		OutputPic->Show();


	}
	private: System::Void loadButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (openFileDialog1->FileName != nullptr) {
				this->label1->Text = "Zdjêcie zosta³o wczytane poprawnie";
				InputPic->Load(openFileDialog1->FileName);
				InputPic->Show();
			}
		}
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void TextTime_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ShowTime_TextChanged_2(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void CheckLoad_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void OutputPic_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

#endif
