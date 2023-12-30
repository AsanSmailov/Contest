class ScreenPrintStrategy: public PrintStrategy {
    public:
        void print(const Document& document) override{
            std::cout << document.get() << "\n";
        }
};

class StringPrintStrategy: public PrintStrategy{
    private:
        std::string buffer;
        int counter = 0;
    public:
        void print(const Document& document) override{
            counter++;
            buffer += "--- doc "+ std::to_string(counter) + " ---\n" + document.get() + "\n";
            
        }
        std::string getPrintedDocuments() const{
            return buffer;
        }
};

class MockPrintStrategy: public PrintStrategy{
    private:
        int counter = 0;
    public:
        void print(const Document& document) override{
            counter++;
        }
        int getPrintedDocumentsCount() const{
            return counter;
        }
};