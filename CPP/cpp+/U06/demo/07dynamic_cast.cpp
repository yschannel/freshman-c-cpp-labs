void printObject(Shape &shape)
{
    Circle *c = dynamic_cast<Circle *>(p);
    if (c != nullptr)
    {
        cout << p1->getRadius() << endl;
    }
}