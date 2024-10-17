import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Pessoa> pessoas = new ArrayList<>();

        // Solicitar o número de pessoas a serem cadastradas
        System.out.print("Quantas pessoas você deseja cadastrar? ");
        int n = sc.nextInt();
        sc.nextLine();  // Consumir a linha restante do Enter

        // Cadastrar as pessoas
        for (int i = 0; i < n; i++) {
            System.out.println("\nCadastro da pessoa " + (i + 1) + ":");
            
            System.out.print("Nome: ");
            String nome = sc.nextLine();

            System.out.print("Idade: ");
            int idade = sc.nextInt();
            sc.nextLine();  // Consumir o Enter

            System.out.print("Endereço: ");
            String endereco = sc.nextLine();

            // Criar uma nova pessoa e adicionar ao ArrayList
            Pessoa pessoa = new Pessoa(nome, idade, endereco);
            pessoas.add(pessoa);
        }

        // Exibir todas as pessoas cadastradas
        System.out.println("\nPessoas cadastradas:");
        for (Pessoa p : pessoas) {
            System.out.println(p);
        }

        sc.close();
    }
}
