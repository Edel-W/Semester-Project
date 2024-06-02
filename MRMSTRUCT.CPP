#include <iostream>
#include <string>

using namespace std;

struct Customer {
    int customerID;
    string name;
    string address;
    string phoneNumber;
};

void registerCust(Customer &customer) {
    cout << "--------------------CUSTOMER REGISTRATION----------------------" << endl;
    cout << "Enter customer ID: ";
    cin >> customer.customerID;
    cout << "Enter customer name: ";
    cin >> customer.name;
    cout << "Enter customer address: ";
    cin >> customer.address;
    cout << "Enter customer phone number: ";
    cin >> customer.phoneNumber;
    cout << "Customer registered!" << endl;
}

void displayCust(const Customer &customer) {
    cout << "--------------------CUSTOMER INFO----------------------" << endl;
    cout << "Customer ID: " << customer.customerID << endl;
    cout << "Name: " << customer.name << endl;
    cout << "Address: " << customer.address << endl;
    cout << "Phone Number: " << customer.phoneNumber << endl;
    cout << "----------------------------------------------------------------" << endl;
}

struct Movie {
    int movieID;
    string title;
    string genre;
    string releaseDate;
    bool isAvailable;
};

void updateMovieStatus(Movie &movie) {
    cout << "Enter the movie title: ";
    cin >> movie.title;
    if (movie.isAvailable) {
        cout << "Movie " << movie.title << " is Available" << endl;
    } else {
        cout << "Movie " << movie.title << " is Rented" << endl;
    }
}

void displayMovies(const Movie movies[], int movieCount) {
    cout << "--------------------MOVIE LIST----------------------" << endl;
    for (int i = 0; i < movieCount; ++i) {
        cout << "Movie ID: " << movies[i].movieID << endl;
        cout << "Title: " << movies[i].title << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << "Release Date: " << movies[i].releaseDate << endl;
        if (movies[i].isAvailable) {
            cout << "Status: Available" << endl;
        } else {
            cout << "Status: Rented" << endl;
        }
        cout << "----------------------------------------------------------------" << endl;
    }
}

void rentMovie(Customer &customer, int movieID, Movie movies[], int movieCount) {
    for (int i = 0; i < movieCount; ++i) {
        if (movies[i].movieID == movieID) {
            if (movies[i].isAvailable) {
                cout << "Movie " << movies[i].title << " has been rented by " << customer.name << "." << endl;
                movies[i].isAvailable = false;
            } else {
                cout << "Movie " << movies[i].title << " is not available." << endl;
            }
            return;
        }
    }
    cout << "Movie with ID " << movieID << " not found." << endl;
}

struct Rental {
    int rentalID;
    string rentalDate;
    string returnDate;
    int customerID;
    int movieID;
};

void displayRental(Rental &rental) {
    cout << "--------------------RENTAL INFO----------------------" << endl;
    cout << "Customer ID: ";
    cin >> rental.customerID;
    cout << "Rental ID: ";
    cin >> rental.rentalID;
    cout << "Rental Date: ";
    cin >> rental.rentalDate;
    cout << "Return Date: ";
    cin >> rental.returnDate;
    cout << "----------------------------------------------------------------" << endl;
}

struct Payment {
    int paymentID;
    float amount;
    string paymentDate;
    string method;
    string customerName;
};

void processPayment(Payment &payment) {
    cout << "--------------------PAYMENT INFO----------------------" << endl;
    cout << "Enter payment amount: ";
    cin >> payment.amount;
    cout << "Enter payment date (YYY-MM-Dd): ";
    cin >> payment.paymentDate;
    cout << "Enter payment method: ";
    cin >> payment.method;
    cout << "----------------------------------------------------------------" << endl;

    cout << " Processed payment of " << payment.amount << " on " << payment.paymentDate << " via " << payment.method << endl;
}
struct Staff {
    int staffID;
    string name;
    string role;
    string contactInfo;
};

void displayStaff(Staff &staff) {
    cout << "--------------------STAFF INFO----------------------" << endl;
        cout << "Staff ID: " <<staff.staffID << endl;
        cout << "Name: " << staff.name << endl;
        cout << "Role: " << staff.role << endl;
        cout << "Contact Info: " <<staff.contactInfo << endl;
        cout << "----------------------------------------------------------------" << endl;

}

int main() {
    Customer c1;
    registerCust(c1);
    displayCust(c1);

    const int movieCount = 5;
    Movie movieList[movieCount] = {
        {1, "The Shawshank Redemption", "Drama", "1994-09-23", true},
        {2, "The Godfather", "Crime", "1972-03-15", true},
        {3, "The Dark Knight", "Action", "2008-07-18", false},
        {4, "Inception", "Sci-Fi", "2010-07-16", true},
        {5, "Forrest Gump", "Drama", "1994-07-06", true}
    };

    displayMovies(movieList, movieCount);

    int selectedMovieID;
    cout << "Enter the movie ID you want to rent: ";
    cin >> selectedMovieID;
    rentMovie(c1, selectedMovieID, movieList, movieCount);

    Rental r1;
    displayRental(r1);

    Payment p1;
    processPayment(p1);

   Staff staff1 = {1, "Alice", "Clerk", "alice@example.com"};
    displayStaff(staff1);


    return 0;
}