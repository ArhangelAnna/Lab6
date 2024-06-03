#pragma once
#include "Stack.h"

namespace Lab6 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form {
    public:
        MyForm(void) {
            InitializeComponent();
            stack = new ::Stack<double>();
            stack2 = new ::Stack<double>();// Явное указание на глобальное пространство имен
        }

    protected:
        ~MyForm() {
            this->!MyForm();  // Вызов финализатора (деструктора) управляемого ресурса
            if (components) {
                delete components;
            }
        }

        // Финализатор (деструктор) управляемого ресурса
        !MyForm() {
            if (stack) {
                delete stack;
                stack = nullptr;
            }
        }

    private:
        ::Stack<double>* stack;  // Используем явное глобальное пространство имен
        ::Stack<double>* stack2;
        System::ComponentModel::Container^ components;
        System::Windows::Forms::TextBox^ inputBox;
        System::Windows::Forms::ListBox^ listBox;
        System::Windows::Forms::Button^ addButton;
        System::Windows::Forms::Button^ removeButton;
        System::Windows::Forms::Button^ addOpButton;
        System::Windows::Forms::Button^ subOpButton;
        System::Windows::Forms::Button^ mulOpButton;
        System::Windows::Forms::Button^ divOpButton;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::ComboBox^ sortedBox;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Button^ button1;



           System::Windows::Forms::Button^ aboutButton;


           void InitializeComponent(void) {
               this->inputBox = (gcnew System::Windows::Forms::TextBox());
               this->listBox = (gcnew System::Windows::Forms::ListBox());
               this->addButton = (gcnew System::Windows::Forms::Button());
               this->removeButton = (gcnew System::Windows::Forms::Button());
               this->addOpButton = (gcnew System::Windows::Forms::Button());
               this->subOpButton = (gcnew System::Windows::Forms::Button());
               this->mulOpButton = (gcnew System::Windows::Forms::Button());
               this->divOpButton = (gcnew System::Windows::Forms::Button());
               this->aboutButton = (gcnew System::Windows::Forms::Button());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->sortedBox = (gcnew System::Windows::Forms::ComboBox());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->SuspendLayout();
               // 
               // inputBox
               // 
               this->inputBox->ForeColor = System::Drawing::SystemColors::Desktop;
               this->inputBox->Location = System::Drawing::Point(124, 15);
               this->inputBox->Margin = System::Windows::Forms::Padding(4);
               this->inputBox->Name = L"inputBox";
               this->inputBox->Size = System::Drawing::Size(159, 22);
               this->inputBox->TabIndex = 0;
               this->inputBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::inputBox_KeyPress);
               // 
               // listBox
               // 
               this->listBox->ForeColor = System::Drawing::SystemColors::Desktop;
               this->listBox->FormattingEnabled = true;
               this->listBox->ItemHeight = 16;
               this->listBox->Location = System::Drawing::Point(124, 65);
               this->listBox->Margin = System::Windows::Forms::Padding(4);
               this->listBox->Name = L"listBox";
               this->listBox->Size = System::Drawing::Size(159, 116);
               this->listBox->TabIndex = 1;
               // 
               // addButton
               // 
               this->addButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->addButton->Location = System::Drawing::Point(305, 12);
               this->addButton->Margin = System::Windows::Forms::Padding(4);
               this->addButton->Name = L"addButton";
               this->addButton->Size = System::Drawing::Size(100, 28);
               this->addButton->TabIndex = 2;
               this->addButton->Text = L"Добавить";
               this->addButton->UseVisualStyleBackColor = true;
               this->addButton->Click += gcnew System::EventHandler(this, &MyForm::addButton_Click);
               // 
               // removeButton
               // 
               this->removeButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->removeButton->Location = System::Drawing::Point(305, 62);
               this->removeButton->Margin = System::Windows::Forms::Padding(4);
               this->removeButton->Name = L"removeButton";
               this->removeButton->Size = System::Drawing::Size(100, 28);
               this->removeButton->TabIndex = 3;
               this->removeButton->Text = L"Удалить";
               this->removeButton->UseVisualStyleBackColor = true;
               this->removeButton->Click += gcnew System::EventHandler(this, &MyForm::removeButton_Click);
               // 
               // addOpButton
               // 
               this->addOpButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->addOpButton->Location = System::Drawing::Point(124, 189);
               this->addOpButton->Margin = System::Windows::Forms::Padding(4);
               this->addOpButton->Name = L"addOpButton";
               this->addOpButton->Size = System::Drawing::Size(100, 28);
               this->addOpButton->TabIndex = 4;
               this->addOpButton->Text = L"Сложить";
               this->addOpButton->UseVisualStyleBackColor = true;
               this->addOpButton->Click += gcnew System::EventHandler(this, &MyForm::addOpButton_Click);
               // 
               // subOpButton
               // 
               this->subOpButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->subOpButton->Location = System::Drawing::Point(305, 189);
               this->subOpButton->Margin = System::Windows::Forms::Padding(4);
               this->subOpButton->Name = L"subOpButton";
               this->subOpButton->Size = System::Drawing::Size(100, 28);
               this->subOpButton->TabIndex = 5;
               this->subOpButton->Text = L"Вычесть";
               this->subOpButton->UseVisualStyleBackColor = true;
               this->subOpButton->Click += gcnew System::EventHandler(this, &MyForm::subOpButton_Click);
               // 
               // mulOpButton
               // 
               this->mulOpButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->mulOpButton->Location = System::Drawing::Point(305, 247);
               this->mulOpButton->Margin = System::Windows::Forms::Padding(4);
               this->mulOpButton->Name = L"mulOpButton";
               this->mulOpButton->Size = System::Drawing::Size(100, 28);
               this->mulOpButton->TabIndex = 6;
               this->mulOpButton->Text = L"Умножить";
               this->mulOpButton->UseVisualStyleBackColor = true;
               this->mulOpButton->Click += gcnew System::EventHandler(this, &MyForm::mulOpButton_Click);
               // 
               // divOpButton
               // 
               this->divOpButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->divOpButton->Location = System::Drawing::Point(124, 247);
               this->divOpButton->Margin = System::Windows::Forms::Padding(4);
               this->divOpButton->Name = L"divOpButton";
               this->divOpButton->Size = System::Drawing::Size(100, 28);
               this->divOpButton->TabIndex = 7;
               this->divOpButton->Text = L"Разделить";
               this->divOpButton->UseVisualStyleBackColor = true;
               this->divOpButton->Click += gcnew System::EventHandler(this, &MyForm::divOpButton_Click);
               // 
               // aboutButton
               // 
               this->aboutButton->ForeColor = System::Drawing::SystemColors::Desktop;
               this->aboutButton->Location = System::Drawing::Point(305, 99);
               this->aboutButton->Margin = System::Windows::Forms::Padding(4);
               this->aboutButton->Name = L"aboutButton";
               this->aboutButton->Size = System::Drawing::Size(100, 82);
               this->aboutButton->TabIndex = 8;
               this->aboutButton->Text = L"О программе";
               this->aboutButton->UseVisualStyleBackColor = true;
               this->aboutButton->Click += gcnew System::EventHandler(this, &MyForm::aboutButton_Click);
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label1->Location = System::Drawing::Point(12, 18);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(53, 20);
               this->label1->TabIndex = 9;
               this->label1->Text = L"Ввод";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label2->Location = System::Drawing::Point(12, 65);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(96, 20);
               this->label2->TabIndex = 10;
               this->label2->Text = L"Элементы";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label3->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label3->Location = System::Drawing::Point(4, 189);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(92, 20);
               this->label3->TabIndex = 11;
               this->label3->Text = L"Опирации";
               // 
               // sortedBox
               // 
               this->sortedBox->ForeColor = System::Drawing::SystemColors::Desktop;
               this->sortedBox->FormattingEnabled = true;
               this->sortedBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
                   L"b.Вставками;", L"c.Пузырьковая;", L"d.Шейкера;",
                       L"e.Быстрая."
               });
               this->sortedBox->Location = System::Drawing::Point(124, 314);
               this->sortedBox->Name = L"sortedBox";
               this->sortedBox->Size = System::Drawing::Size(159, 24);
               this->sortedBox->TabIndex = 12;
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(204)));
               this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
               this->label4->Location = System::Drawing::Point(8, 314);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(110, 20);
               this->label4->TabIndex = 13;
               this->label4->Text = L"Сортировки";
               // 
               // button1
               // 
               this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
               this->button1->Location = System::Drawing::Point(299, 310);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(106, 28);
               this->button1->TabIndex = 14;
               this->button1->Text = L"Сортировать";
               this->button1->UseVisualStyleBackColor = true;
               this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
               // 
               // MyForm
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::SystemColors::Desktop;
               this->ClientSize = System::Drawing::Size(421, 358);
               this->Controls->Add(this->button1);
               this->Controls->Add(this->label4);
               this->Controls->Add(this->sortedBox);
               this->Controls->Add(this->label3);
               this->Controls->Add(this->label2);
               this->Controls->Add(this->label1);
               this->Controls->Add(this->aboutButton);
               this->Controls->Add(this->divOpButton);
               this->Controls->Add(this->mulOpButton);
               this->Controls->Add(this->subOpButton);
               this->Controls->Add(this->addOpButton);
               this->Controls->Add(this->removeButton);
               this->Controls->Add(this->addButton);
               this->Controls->Add(this->listBox);
               this->Controls->Add(this->inputBox);
               this->Margin = System::Windows::Forms::Padding(4);
               this->Name = L"MyForm";
               this->Text = L"Калькулятор стека";
               this->ResumeLayout(false);
               this->PerformLayout();

           }

           System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
               double value;
               if (Double::TryParse(inputBox->Text, value)) {
                   stack->push(value);
                   listBox->Items->Add(value);
                   inputBox->Clear();
               }
               else {
                   MessageBox::Show("Введите корректное число", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           System::Void removeButton_Click(System::Object^ sender, System::EventArgs^ e) {
               if (!stack->isEmpty()) {
                   stack->pop();
                   listBox->Items->RemoveAt(listBox->Items->Count - 1);
               }
               else {
                   MessageBox::Show("Стек пуст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           System::Void addOpButton_Click(System::Object^ sender, System::EventArgs^ e) {
               PerformOperation(Operations::Add);
           }

           System::Void subOpButton_Click(System::Object^ sender, System::EventArgs^ e) {
               PerformOperation(Operations::Subtract);
           }

           System::Void mulOpButton_Click(System::Object^ sender, System::EventArgs^ e) {
               PerformOperation(Operations::Multiply);
           }

           System::Void divOpButton_Click(System::Object^ sender, System::EventArgs^ e) {
               PerformOperation(Operations::Divide);
           }

           System::Void aboutButton_Click(System::Object^ sender, System::EventArgs^ e) {
               MessageBox::Show(this, "Чтобы добавить элемент в стек, введите число в текстовое поле с надписью \"Введите число\" и нажмите кнопку \"Добавить\". \n Введенное число будет добавлено в стек и отображено в списке элементов стека.\n Для удаления элемента из стека нажмите кнопку \"Удалить\". Верхний элемент стека будет удален, и список элементов стека обновится.\n Для выполнения операций выберите операцию из выпадающего списка (например, \"Сумма\", \"Разность\", \"Умножение\", \"Деление\"), введите число для выполнения операции и нажмите кнопку \"Выполнить\". Результат операции будет отображен, и стек обновится. Чтобы отсортировать стек, нажмите кнопку \"Сортировка\".", "info", MessageBoxButtons::OK, MessageBoxIcon::Information);
           }

           enum class Operations {
               Add,
               Subtract,
               Multiply,
               Divide
           };

           void PerformOperation(Operations operation) {
               double operand;
               if (Double::TryParse(inputBox->Text, operand)) {
                   if (!stack->isEmpty()) {                       
                       switch (operation) {
                       case Operations::Add:
                           while (!stack->isEmpty()) {
                               double result;
                               double top = stack->top();
                               result = top + operand;
                               stack2->push(result);
                               stack->pop(); // Удаляем элемент из первого стека
                           }

                           // Очищаем listBox
                           listBox->Items->Clear();

                           // Переносим элементы обратно из второго стека в первый и обновляем listBox
                           while (!stack2->isEmpty()) {
                               double top = stack2->top();
                               stack->push(top);
                               listBox->Items->Add(top);
                               stack2->pop(); // Удаляем элемент из второго стека
                           }
                           break;
                       case Operations::Subtract:
                           while (!stack->isEmpty()) {
                               double result;
                               double top = stack->top();
                               result = top - operand;
                               stack2->push(result);
                               stack->pop(); // Удаляем элемент из первого стека
                           }

                           // Очищаем listBox
                           listBox->Items->Clear();

                           // Переносим элементы обратно из второго стека в первый и обновляем listBox
                           while (!stack2->isEmpty()) {
                               double top = stack2->top();
                               stack->push(top);
                               listBox->Items->Add(top);
                               stack2->pop(); // Удаляем элемент из второго стека
                           }
                           break;
                       case Operations::Multiply:
                           while (!stack->isEmpty()) {
                               double result;
                               double top = stack->top();
                               result = top * operand;
                               stack2->push(result);
                               stack->pop(); // Удаляем элемент из первого стека
                           }

                           // Очищаем listBox
                           listBox->Items->Clear();

                           // Переносим элементы обратно из второго стека в первый и обновляем listBox
                           while (!stack2->isEmpty()) {
                               double top = stack2->top();
                               stack->push(top);
                               listBox->Items->Add(top);
                               stack2->pop(); // Удаляем элемент из второго стека
                           }
                           break;
                       case Operations::Divide:
                           if (operand != 0) {
                               while (!stack->isEmpty()) {
                                   double result;
                                   double top = stack->top();
                                   result = top / operand;
                                   stack2->push(result);
                                   stack->pop(); // Удаляем элемент из первого стека
                               }

                               // Очищаем listBox
                               listBox->Items->Clear();

                               // Переносим элементы обратно из второго стека в первый и обновляем listBox
                               while (!stack2->isEmpty()) {
                                   double top = stack2->top();
                                   stack->push(top);
                                   listBox->Items->Add(top);
                                   stack2->pop(); // Удаляем элемент из второго стека
                               }
                               break;
                           }
                           else {
                               MessageBox::Show("Деление на ноль невозможно", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                               return;
                           }
                           break;
                       }
                   }
                   else {
                       MessageBox::Show("Стек пуст", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                   }
               }
               else {
                   MessageBox::Show("Введите корректное число", "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
         if (this->sortedBox->SelectedItem == "b.Вставками;") {
            listBox->Items->Clear();
            stack->insertionSort();
            while (!stack->isEmpty()) {
                double top = stack->top();
                stack2->push(top);
                stack->pop(); // Удаляем элемент из первого стека
            }

            // Переносим элементы обратно из второго стека в первый и обновляем listBox
            while (!stack2->isEmpty()) {
                double top = stack2->top();
                stack->push(top);
                listBox->Items->Add(top);
                stack2->pop(); // Удаляем элемент из второго стека
            }
        }
        else if (this->sortedBox->SelectedItem == "c.Пузырьковая;") {
            listBox->Items->Clear();
            stack->bubbleSort();
            while (!stack->isEmpty()) {
                double top = stack->top();
                stack2->push(top);
                stack->pop(); // Удаляем элемент из первого стека
            }

            // Переносим элементы обратно из второго стека в первый и обновляем listBox
            while (!stack2->isEmpty()) {
                double top = stack2->top();
                stack->push(top);
                listBox->Items->Add(top);
                stack2->pop(); // Удаляем элемент из второго стека
            }
        }
        else if (this->sortedBox->SelectedItem == "d.Шейкера;") {
            listBox->Items->Clear();
            stack->cocktailShakerSort();
            while (!stack->isEmpty()) {
                double top = stack->top();
                stack2->push(top);
                stack->pop(); // Удаляем элемент из первого стека
            }

            // Переносим элементы обратно из второго стека в первый и обновляем listBox
            while (!stack2->isEmpty()) {
                double top = stack2->top();
                stack->push(top);
                listBox->Items->Add(top);
                stack2->pop(); // Удаляем элемент из второго стека
            }
        }
        else if (this->sortedBox->SelectedItem == "e.Быстрая.") {
            listBox->Items->Clear();
            stack->quickSort(0, stack->size() - 1);
            while (!stack->isEmpty()) {
                double top = stack->top();
                stack2->push(top);
                stack->pop(); // Удаляем элемент из первого стека
            }

            // Переносим элементы обратно из второго стека в первый и обновляем listBox
            while (!stack2->isEmpty()) {
                double top = stack2->top();
                stack->push(top);
                listBox->Items->Add(top);
                stack2->pop(); // Удаляем элемент из второго стека
            }
        }
        else {
            MessageBox::Show(this, "Выберете сортировку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

private: System::Void inputBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    if (((e->KeyChar >= '0') && (e->KeyChar <= '9')) || (e->KeyChar == ','))
    {
        return;
    }
    e->Handled = true;
}
};
}