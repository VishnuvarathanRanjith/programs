const generalQuestions = [
    {},
    {
        question: "Who is the Prime Minister of India?",
        answer: "Narendra Modi",
        option: ["Rahul Gandhi", "Narendra Modi", "Stalin", "Seeman"]
    },
    {
        question: "Which country is also known as Bharat?",
        answer: "India",
        option: ["United Nations", "United States of America", "Brazil", "India"]
    },
    {
        question: "How many states are there in India?",
        answer: "28",
        option: ["28", "29", "31", "32"]
    }
];

const SportsQuizQuestions = [
    {},
    {
        question: "Who won the FIFA World Cup in 2018?",
        answer: "France",
        option: ["Germany", "Brazil", "France", "Argentina"]
    },
    {
        question: "Which country is known for inventing the game of cricket?",
        answer: "England",
        option: ["India", "Australia", "England", "South Africa"]
    },
    {
        question: "Who holds the record for the most goals in football history?",
        answer: "Cristiano Ronaldo",
        option: ["Lionel Messi", "Cristiano Ronaldo", "Pele", "Diego Maradona"]
    },
    {
        question: "In which year did Usain Bolt set the world record for the 100 meters?",
        answer: "2009",
        option: ["2008", "2010", "2009", "2012"]
    },

];
const ComputerScienceQuizQuestions = [
    {},
    {
        question: "Which of these is a type of cloud computing service?",
        answer: "SaaS",
        option: ["SaaS", "IaaS", "PaaS", "All of the above"]
    },
    {
        question: "What does the acronym 'RAM' stand for?",
        answer: "Random Access Memory",
        option: ["Read Access Memory", "Random Access Memory", "Read and Write Memory", "Return Access Memory"]
    },
    {
        question: "Which sorting algorithm has the best average-case time complexity?",
        answer: "Merge Sort",
        option: ["Quick Sort", "Merge Sort", "Bubble Sort", "Insertion Sort"]
    },
    {
        question: "Which company developed the first computer mouse?",
        answer: "Xerox",
        option: ["IBM", "Microsoft", "Apple", "Xerox"]
    }
   ];

let score = 0;
let answered = {};
let currentIndex = 1;

function Start() {
    let button = document.createElement('button');
    button.textContent = "Start Quiz";
    document.body.appendChild(button);
    button.onclick = function () {
        button.remove();
        q();
    };
}

function q() {
    let sports = document.createElement("button");
    sports.textContent = "Sports";
    let general = document.createElement("button");
    general.textContent = "General";
    let computerScience = document.createElement("button");
    computerScience.textContent = "Computer Science";
    document.body.appendChild(computerScience);
    document.body.appendChild(sports);
    document.body.appendChild(general);

    sports.onclick = function () {
        sports.remove();
        Question(SportsQuizQuestions);
    };

    general.onclick = function () {
        general.remove();
        Question(generalQuestions);
    };
    computerScience.onclick = function () {
        general.remove();
        Question(ComputerScienceQuizQuestions);
    };
}

function Question(input) {
    let head = document.createElement("h3");
    document.body.innerHTML = "";
    let ind = document.createElement("p");
    let questionText = document.createElement('p');
    let options = document.createElement("div");
    let message = document.createElement("p");
    let buttonContainer = document.createElement("div");
    let submit = document.createElement("button");
    let nextButton = document.createElement("button");
    let previousButton = document.createElement("button");
    let reset=document.createElement("button");
    let result = document.createElement("h3");
    
    submit.textContent = "Submit";
    submit.disabled = true;
    reset.disabled=true;
    nextButton.textContent = "Next";
    previousButton.textContent = "Previous";
    reset.textContent="Reset";
    buttonContainer.style.marginTop = "20px";

    ind.textContent = `Question ${currentIndex}`;
    questionText.textContent = input[currentIndex].question;
    ans(input, options, currentIndex); 
    document.body.appendChild(ind);
    document.body.appendChild(questionText);
    document.body.appendChild(options);

    nextButton.onclick = function () {
        if (currentIndex < input.length - 1) {
            currentIndex++; 
            Question(input); 
        } else {
            submit.disabled = false;
            message.textContent = "You have reached the end of the quiz!";
            document.body.appendChild(message);
        }
    };

    previousButton.onclick = function () {
        if (currentIndex > 1) {
            currentIndex--; 
            Question(input); 
        } else {
            message.textContent = "You are at the start of the quiz!";
            document.body.appendChild(message);
        }
    };

    submit.onclick = function () {
        result.innerHTML = `Your final score is: ${score}`;
        result.style.color = "blue";
        document.body.appendChild(result);
        submit.disabled = true;
        nextButton.disabled = true;
        previousButton.disabled = true;
        reset.disabled=false;
        message.textContent = "Quiz is ended!";
        message.style.color = "red";
        document.body.appendChild(message);
        displayAns(input,answered, head);   
        reset.onclick=function(){
            window.location.reload();
            reset.disabled=true;
        }
    };

    buttonContainer.appendChild(previousButton);
    buttonContainer.appendChild(nextButton);
    buttonContainer.appendChild(submit);
    buttonContainer.appendChild(reset);
    document.body.appendChild(buttonContainer);
}

function ans(input, options, currentIndex) {
    options.innerHTML = "";
    for (let i = 0; i < input[currentIndex].option.length; i++) {
        let label = document.createElement('label');
        let radio = document.createElement('input');
        radio.type = "radio";
        radio.name = "option";
        radio.value = input[currentIndex].option[i];
        if (answered[currentIndex] === input[currentIndex].option[i]) {
            radio.checked = true;
        }

        radio.onclick = function () {
            let selectedValue = radio.value;
            if (selectedValue === input[currentIndex].answer) {
                score += 10; 
            }
            answered[currentIndex] = radio.value; 
        };

        label.appendChild(radio);
        label.appendChild(document.createTextNode(input[currentIndex].option[i]));
        options.appendChild(label);
        options.appendChild(document.createElement('br'));
    }
}

function displayAns(input,answered, head) {
    head.innerHTML = '';
    for (let index in answered) {
        let p = document.createElement('p');
        let correctAns=document.createElement('p');
        p.textContent = `Question ${parseInt(index) }: You selected ${answered[index]}`;
        correctAns.textContent = `Correct answer is ${input[index].answer}`;
        correctAns.style.color="green";
        head.appendChild(p);
        head.appendChild(correctAns);

    }

    document.body.appendChild(head);
}
Start();
